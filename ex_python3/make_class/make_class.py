class employee:
    def __init__(self, number, name):
        self.number = number
        self.name = name
    
    def getnum(self):
        return self.number
    
    def getname(self):
        return self.name

N = int(input())

employees = []

for _ in range(N):
    command = input().split()
    
    if command[0] == "make":
        number = int(command[1])
        name = command[2]
        emp = employee(number, name)
        employees.append(emp)
        
    elif command[0] == "getnum":
        n = int(command[1])
        if 1 <= n <= len(employees):
            print(employees[n-1].getnum())
            
    elif command[0] == "getname":
        n = int(command[1])
        if 1 <= n <= len(employees):
            print(employees[n-1].getname())