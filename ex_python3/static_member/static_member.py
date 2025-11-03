class Customer:
    def __init__(self, id, age):
        self.id = id
        self.age = age
        self.bill = 0

    def order_food(self, price):
        self.bill += price
    
    def order_softdrink(self, price):
        self.bill += price

    def order_alcohol(self, price):
        pass

class AdultCustomer(Customer):
    def __init__(self, id, age):
        super().__init__(id, age)
        self.discount = False

    def order_alcohol(self, price):
        self.bill += price
        self.discount = True

    def order_food(self, price):
        if self.discount:
            self.bill += max(0, price - 200)
        else:
            self.bill += price

N, K = map(int, input().split())
a = [int(input()) for _ in range(N)]
cnt = 0

customers = []

for i in range(N):
    if (a[i] >= 20):
        customers.append(AdultCustomer(i + 1, a[i]))
    else:
        customers.append(Customer(i + 1, a[i]))

for _ in range(K):
    data = input().split()
    n = int(data[0]) - 1
    c = customers[n]

    if (data[1] == "0"):
        s, m = "alcohol", 500
    elif (data[1] == "A"):
        print(c.bill)
        cnt += 1
        continue
    else:
        s, m = data[1], int(data[2])

    if (s == "food"):
        c.order_food(m)
    elif (s == "softdrink"):
        c.order_softdrink(m)
    elif (s == "alcohol"):
        c.order_alcohol(m)

print(cnt)