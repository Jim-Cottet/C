import dis;

def greet(name):
    return "Hello, World! " + name

dis.dis(greet);
print(greet("John Doe"));