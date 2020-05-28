import re
import sys

arithemetic_operations = {'+': 'ADD', '*': 'MUL', '-': 'SUB', '/': 'DIV'}
conditional_operations = {'==': 'EQ', '!=': 'NE', '<': 'GE', '>': 'LE', '<=': 'GT', '>=': 'LT'}
register_values = {}
register_available = ['R0', 'R1', 'R2', 'R3', 'R4', 'R5', 'R6', 'R7', 'R8', 'R9', 'R10', 'R11', 'R12', 'R13']
occupied_registers = []


def get_register():
    if(len(register_available) != 0):
        register = register_available.pop(0)
        occupied_registers.append(register)
    else:
        register = occupied_registers.pop(0)
        mem = register_values.pop(register)
        occupied_registers.append(register)

    return register


def check_register(operand):
    for key in register_values.keys():
        if(operand == register_values[key]):
            register = key
            occupied_registers.remove(register)
            occupied_registers.append(register)
            return register
    
    register = get_register()
    if(operand.isnumeric()):
        print("\tMOV"+" "+register+" "+"#"+operand)
    else:
        print("\tLDR"+" "+register+" "+operand)
    register_values[register] = operand
    return register


def arithemetic_operation(line, operation):
    register1 = check_register(line[2])
    if(line[4].isnumeric()):
        register2 = "#"+str(line[4])
    else:
        register2 = check_register(line[4])
    register3 = get_register()
    print("\t"+operation+" "+register3+" "+register1+" "+register2)
    regex_match = re.findall("^t[0-9]*$", line[0])
    if(len(regex_match)):
        pass
    else:

        print("\tSTR "+register3+" "+line[0])

    if(line[0] == line[2]):
        occupied_registers.remove(register1)
        register_available.append(register1)
        register_values.pop(register1)

    elif(line[0] == line[4] and not line[4].isnumeric()):
        occupied_registers.remove(register2)
        register_available.append(register2)
        register_values.pop(register2)
    register_values[register3] = line[0]


def conditional_operation(line):
    register1 = check_register(line[2])
    if(line[4].isnumeric()):
        register2 = "#"+str(line[4])
    else:
        register2 = check_register(line[4])
    print("\tCMP "+register1+" "+register2)


condition_used = " "


def eval_statements(line):

    global condition_used
    if 'if' in line:
        for operator in conditional_operations:
            if operator in line:
                condition_used = conditional_operations[operator]
                #print(condition_used)
                register1 = check_register(line[1])
                if(line[3].isnumeric()):
                    register2 = "#"+str(line[3])
                else:
                    register2 = check_register(line[3])
                print("\tCMP "+register1+" "+register2)
                print("\tB"+condition_used+' '+line[5])
                return          
            
    
    for operator in arithemetic_operations:
        if operator in line and len(line) == 5:
            arithemetic_operation(line, arithemetic_operations[operator])
            return

    for operator in conditional_operations:
        if operator in line and len(line) == 5:
            condition_used = conditional_operations[operator]
            conditional_operation(line)
            return
    if(len(line) == 1):
        regex_match = re.findall("^[A-Za-z0-9]*:$", line[0])
        if(len(regex_match)):
            print(line[0])
            return

    if 'iffalse' in line and len(line) == 4:
        print("\t"+condition_used+" "+line[3])
        return

    if 'goto' in line and len(line) == 2:
        print("\tB "+line[1])
        return
    if 'true' in line and len(line) == 4:
        print("\tB "+line[3])
        return   

    if '=' in line and len(line) == 3:
        register1 = check_register(line[2])
        print("\tSTR "+register1+" "+line[0])
        regex_match = re.findall("^t[0-9]*$", line[2])
        if(line[2].isnumeric() or len(regex_match)):
            pass
        else:
            register2 = get_register()

        for register in register_values.keys():
            if(register_values[register] == line[0]):
                register_values.pop(register)
                occupied_registers.remove(register)
                register_available.append(register)
                break

        if(not line[2].isnumeric() and not len(regex_match)):
            register_values[register2] = line[0]

        if(register_values[register1].isnumeric() or len(regex_match)):
            occupied_registers.remove(register1)
            occupied_registers.append(register1)
            register_values[register1] = line[0]
        return


if __name__ == "__main__":
    print("TARGET CODE\n")
    opti_code = open("/home/acer/Aishwarya/CD_Project/target/input1.txt", "r")
    list_of_lines = opti_code.readlines()

    for i in range(len(list_of_lines)):
        list_of_lines[i] = list_of_lines[i].replace('\n', '')
        list_of_lines[i] = list_of_lines[i].split()

    for i in range(len(list_of_lines)):
        eval_statements(list_of_lines[i])
        print('\n')
