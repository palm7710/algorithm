class Employee:
    def __init__(self, number, name):
        self.number = number
        self.name = name
    
    def getnumber(self):
        return self.number

    def getname(self):
        return self.name

N = int(input())

employees = []

for _ in range(N):
    command = input().split()

    if (command[0] == "make"):
        emp = Employee(command[1], command[2])
        employees.append(emp)

    elif (command[0] == "getnum"):
        n = int(command[1])
        print(employees[n-1].getnumber())

    elif (command[0] == "getname"):
        n = int(command[1])
        print(employees[n-1].getname())