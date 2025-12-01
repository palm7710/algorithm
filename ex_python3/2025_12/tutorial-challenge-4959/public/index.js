const trackButton = document.getElementById("track-button");
const trackText = document.getElementById("track-text");

trackButton.addEventListener("click", () => {
  trackText.textContent = "hello track";
});
