class employee:
    def __init__(self, number, name):
        self.number = number
        self.name = name

    def getnum(self):
        return self.number
    
    def getname(self):
        return self.name

    def setnum(self, new_number):
        self.number = new_number

    def setname(self, new_name):
        self.name = new_name

N = int(input())

employees = []

for _ in range(N):
    command = input().split()

    if (command[0] == "make"):
        emp = employee(command[1], command[2])
        employees.append(emp)

    elif (command[0] == "getnum"):
        n = int(command[1])
        print(employees[n-1].getnum())

    elif (command[0] == "getname"):
        n = int(command[1])
        print(employees[n-1].getname())

    elif (command[0] == "change_num"):
        n, new_number = int(command[1]), int(command[2])
        employees[n-1].setnum(new_number)

    elif (command[0] == "change_name"):
        n, new_name = int(command[1]), command[2]
        employees[n-1].setname(new_name)