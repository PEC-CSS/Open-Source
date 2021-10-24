import csv

credentials = {}
with open("database.csv", "r") as csv_file:
    csv_reader = csv.reader(csv_file, delimiter = ",")
    next(csv_reader)
    for row in csv_reader:
        #credentials[row[1]] = row[2]
        credentials[row[0]] = row[1]

def choice():
    c = input("Do you want to Login(l) or Signup(s)? : ")
    if c == 'l' or c == 'L':
        login()
    elif c == 's' or c == 'S':
        signUp()
    else:
        print("Please give correct input (l/s)")
        choice()

def login():
    print("Welcome to the Login page")
    def userLogin():
        username = input("Please enter username : ")
        if username in credentials.keys():
            password = input("Please enter password : ")
            if credentials.get(username) == password:
                print("Login Successful!")
                c = input("Do you want to Login(l) or Signup(s) again? : ")
                if c == 'l' or c == 'L':
                    login()
                elif c == 's' or c == 'S':
                    signUp()
                else:
                    print("OK Bye!")
            else:
                print("Wrong credentials, please try again")
                userLogin()
        else:
            print("No username found, please try again!")
            userLogin()

    userLogin()

def signUp():
    print("Welcome to the Sign Up page")
    def userSignUp():
        userName = input("Please enter username : ")
        if userName in credentials.keys():
            print("The username is already taken, please try again")
            userSignUp()
        else:
            password = input("Please enter password : ")
            credentials[userName] = password
            print("Signed Up Successful!")
            c = input("Do you want to login now? (y/n) : ")
            if c == 'y' or c == 'Y':
                login()
            else:
                print("OK Bye!")
    
    userSignUp()

print("Welcome!")
choice()
print(credentials)

with open("predefined.csv", "r") as infile, open("database.csv", "w", newline = "") as outfile:
    r = csv.DictReader(infile)
    w = csv.DictWriter(outfile, r.fieldnames)
    w.writeheader()

    temp_dict = {row["Username"]: row["Password"] for row in r}

    for k in credentials.keys():
        if k not in temp_dict:
            temp_dict[k] = credentials[k]
    
    for value in temp_dict:
        #w.writerow({"Sr. No.": 1, "Username": value, "Password": temp_dict[value]})
        w.writerow({"Username": value, "Password": temp_dict[value]})

print(credentials)