async function main(argv: string[]) {
  const token = argv[0];
  const jsonStr = argv[1];

  if (!token || !jsonStr) {
    console.log("missing arguments");
    return;
  }

  let params;

  try {
    params = JSON.parse(jsonStr);
  } catch (e) {
    console.error("invalid json");
    return;
  }

  const searchUrl =
    "https://challenge-server.tracks.run/hotel-reservation/hotels";

  const searchResponse = await fetch(
    `${searchUrl}?keyword=${encodeURIComponent(params.keyword)}&checkin=${
      params.checkin
    }&checkout=${params.checkout}&number=${params.number}`,
    {
      method: "GET",
      headers: {
        "X-ACCESS-TOKEN": token,
      },
    }
  );

  const searchData = await searchResponse.json();

  const hotels = searchData;

  const searchSuccess =
    Array.isArray(hotels) &&
    hotels.some(
      (hotel: any) =>
        Array.isArray(hotel.plans) &&
        hotel.plans.flat().some((p: any) => p.id === params.plan_id)
    );

  const reserveUrl =
    "https://challenge-server.tracks.run/hotel-reservation/reservations";

  if (searchSuccess) {
    const reserve = await fetch(reserveUrl, {
      method: "POST",
      headers: {
        "X-ACCESS-TOKEN": token,
        "Content-Type": "application/json",
      },
      body: JSON.stringify(params),
    });
    const resData = await reserve.json();

    console.log(resData.id);
    return;
  }
  console.log("plan not found");

  const reserveResponse = await fetch(reserveUrl, {
    method: "POST",
    headers: {
      "X-ACCESS-TOKEN": token,
      "Content-Type": "application/json",
    },
    body: JSON.stringify(params),
  });

  if (reserveResponse.status == 404) {
    console.log("plan_id does not exist");
    return;
  }
  if (reserveResponse.status === 409) {
    console.log("full reservations");
    return;
  }

  console.log("plan_id exists. You should change search keyword.");
}

main(process.argv.slice(2));
