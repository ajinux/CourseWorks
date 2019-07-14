
### Filters


```python
def filterLowerCaseLetters(letter):
    if letter.isupper():
        return False
    return True

chars = "Can you filTer Me!!"
print(list(filter(filterLowerCaseLetters, chars)))
```

    ['a', 'n', ' ', 'y', 'o', 'u', ' ', 'f', 'i', 'l', 'e', 'r', ' ', 'e', '!', '!']


### Map


```python
def toGrade(mark):
    if mark > 90:
        return "A"
    elif mark > 80:
        return "B"
    else:
        return "C"

marks = [87,23,12,100,32,67]
print(list(map(toGrade, marks)))
```

    ['B', 'C', 'C', 'A', 'C', 'C']


***
### Itertools - cycle


```python
import itertools

jobs = ["dev", "marketing"]
job_cycle = itertools.cycle(jobs)
print(next(job_cycle))
print(next(job_cycle))
print(next(job_cycle)) #back to the begining

```

    dev
    marketing
    dev


***
### Itertools - count


```python
import itertools

count = itertools.count(100,10) #increases the counter in 10 from 100
print(next(count))
print(next(count))
```

    100
    110


***
### Itertools - accumulate


```python
import itertools, operator

marks = [87,23,12,100,32,67]
print("original values {0}".format(marks))

accu = itertools.accumulate(marks)
print("With default addition {0}".format(list(accu)))

accu = itertools.accumulate(marks, max)
print("With max {0}".format(list(accu)))

accu = itertools.accumulate(marks, min)
print("With min {0}".format(list(accu)))

accu = itertools.accumulate(marks, operator.mul)
print("With multiply operator {0}".format(list(accu)))
```

    original values [87, 23, 12, 100, 32, 67]
    With default addition [87, 110, 122, 222, 254, 321]
    With max [87, 87, 87, 100, 100, 100]
    With min [87, 23, 12, 12, 12, 12]
    With multiply operator [87, 2001, 24012, 2401200, 76838400, 5148172800]


***
### Itertools - chain


```python
import itertools

# use chain to connect sequences together
x = itertools.chain("ABCD", "1234", "XYZ")
print(list(x))
```

    ['A', 'B', 'C', 'D', '1', '2', '3', '4', 'X', 'Y', 'Z']


***
### Itertools - dropwhile & takewhile


```python
import itertools

# predicate function
def testFunction(x):
    return x < 40

multiple10 = [10,20,30,40,50,60,70,80,90,100]

print(list(itertools.dropwhile(testFunction, multiple10))) # drops value untill predicate function returns True 
print(list(itertools.takewhile(testFunction, multiple10))) # takes value untill predicate function returns True
```

    [40, 50, 60, 70, 80, 90, 100]
    [10, 20, 30]


***
### Functions


```python
print(filter.__doc__) # documentation can be obtained from __doc__
```

    filter(function or None, iterable) --> filter object
    
    Return an iterator yielding those items of iterable for which function(item)
    is true. If function is None, return the items that are true.



```python
def myFunction(agr1, arg2=None):
    """
myFunction(arg1, arg2=None) --> prints the args passed
Parameters:
    arg1: 1st arg.
    arg2: 2nd arg.Defaults to None.
    """
    print(arg1, arg2)
    
print(myFunction.__doc__)
```

    
    myFunction(arg1, arg2=None) --> prints the args passed
    Parameters:
        arg1: 1st arg.
        arg2: 2nd arg.Defaults to None.
        


***
### Variable number arguments


```python
def addition(*numbers):
    # numbers data type - tuple
    return sum(numbers)

print(addition(1,4))
print(addition(4,123,10))
print(addition(*[32,1234,23]))
```

    5
    137
    1289


***
### Funtions - lambda (anonymous function)


```python
# syntax:
#    lambda (parameters) : (expression)
def CelsisusToFahrenheit(temp):
    return (temp * 9/5) + 32


def FahrenheitToCelsisus(temp):
    return (temp-32) * 5/9

ctemps = [0, 12, 34, 100]
ftemps = [32, 65, 100, 212]

# Normal way
print(list(map(CelsisusToFahrenheit, ctemps)))
print(list(map(FahrenheitToCelsisus, ftemps)))

#using lambdas
print("Using lambdas:")
print(list(map(lambda t: (t*9/5) + 32, ctemps)))
print(list(map(lambda t: (t-32)*5/9, ftemps)))

```

    [32.0, 53.6, 93.2, 212.0]
    [0.0, 18.333333333333332, 37.77777777777778, 100.0]
    Using lambdas:
    [32.0, 53.6, 93.2, 212.0]
    [0.0, 18.333333333333332, 37.77777777777778, 100.0]


***
### Collections - Named tuple


```python
import collections

Point = collections.namedtuple("Point", "x y")
p1 = Point(10,20)
p2 = Point(3,4)
print(p1, p2)
print(p1.x, p2.y)
# Allows replacement
p1 = p1._replace(x=11)
print(p1)
```

    Point(x=10, y=20) Point(x=3, y=4)
    10 4
    Point(x=11, y=20)


***
### Collections - defaultdict


```python
from collections import defaultdict

fruits = ['apple', 'pear', 'orange', 'banana',
              'apple', 'grape', 'banana', 'banana']

# intializes initial value to int default value 0
fruitCounter = defaultdict(int)

# intializes initial value to 100
# fruitCounter = defaultdict(lambda: 100)

# Count the elements in the list
for fruit in fruits:
    fruitCounter[fruit] += 1

# print the result
for (k, v) in fruitCounter.items():
    print(k + ": " + str(v))
```

    apple: 102
    pear: 101
    orange: 101
    banana: 103
    grape: 101


***
### Collections - Counters


```python
from collections import Counter

# list of students in class 1
class1 = ["Bob", "James", "Chad", "Darcy", "Penny", "Hannah"
          "Kevin", "James", "Melanie", "Becky", "Steve", "Frank"]

# list of students in class 2
class2 = ["Bill", "Barry", "Cindy", "Debbie", "Frank",
          "Gabby", "Kelly", "James", "Joe", "Sam", "Tara", "Ziggy"]

# Create a Counter for class1 and class2
c1 = Counter(class1)
c2 = Counter(class2)

# How many students in class 1 named James?
print(c1["James"])

# How many students are in class 1?
print(sum(c1.values()), "students in class 1")

# Combine the two classes
c1.update(class2)
print(sum(c1.values()), "students in class 1 and 2")

# What's the most common name in the two classes?
print(c1.most_common(3))

# Separate the classes again
c1.subtract(class2)
print(c1.most_common(1))

# What's common between the two classes?
print(c1 & c2)
```

    2
    11 students in class 1
    23 students in class 1 and 2
    [('James', 3), ('Frank', 2), ('Bob', 1)]
    [('James', 2)]
    Counter({'James': 1, 'Frank': 1})


***
### Collections - ordered dict


```python
from collections import OrderedDict

# list of sport teams with wins and losses
sportTeams = [("Royals", (18, 12)), ("Rockets", (24, 6)), 
            ("Cardinals", (20, 10)), ("Dragons", (22, 8)),
            ("Kings", (15, 15)), ("Chargers", (20, 10)), 
            ("Jets", (16, 14)), ("Warriors", (25, 5))]

# sort the teams by number of wins
sortedTeams = sorted(sportTeams, key=lambda t: t[1][0], reverse=True)

# create an ordered dictionary of the teams
teams = OrderedDict(sortedTeams)
print(teams)

# Use popitem to remove the top item
tm, wl = teams.popitem(False)
print("Top team: ", tm, wl)

# What are next the top 4 teams?
for i, team in enumerate(teams, start=1):
    print(i, team)
    if i == 4:
        break

# test for equality
a = OrderedDict({"a": 1, "b": 2, "c": 3})
b = OrderedDict({"a": 1, "c": 3, "b": 2})
print("Equality test: ", a == b)

```

    OrderedDict([('Warriors', (25, 5)), ('Rockets', (24, 6)), ('Dragons', (22, 8)), ('Cardinals', (20, 10)), ('Chargers', (20, 10)), ('Royals', (18, 12)), ('Jets', (16, 14)), ('Kings', (15, 15))])
    Top team:  Warriors (25, 5)
    1 Rockets
    2 Dragons
    3 Cardinals
    4 Chargers
    Equality test:  False


***
### Collection - Deque


```python
import collections
import string

# initialize a deque with lowercase letters
d = collections.deque(string.ascii_lowercase)

# deques support the len() function
print("Item count: " + str(len(d)))

# deques can be iterated over
for elem in d:
    print(elem.upper(), end=",")

# manipulate items from either end
d.pop()
d.popleft()
d.append(2)
d.appendleft(1)
print("\n\nAfter poping and appending - {0}".format(d))

# rotate the deque
print("\nBefore rotating - {0}".format(d))
d.rotate(1)
print("\nAfter rotating by 1 - {0}".format(d))
```

    Item count: 26
    A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
    
    After poping and appending - deque([1, 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 2])
    
    Before rotating - deque([1, 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 2])
    
    After rotating by 1 - deque([2, 1, 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'])


***
### Class - Enum


```python
from enum import Enum, unique, auto

@unique #value should be unique
class Fruit(Enum):
    APPLE = 1
    BANANA = 2
    ORANGE = 3
    TOMATO = 4
    PEAR = auto()

# enums have human-readable values and types
print(Fruit.APPLE)
print(type(Fruit.APPLE))
print(repr(Fruit.APPLE))

# enums have name and value properties
print(Fruit.APPLE.name, Fruit.APPLE.value)

# print the auto-generated value
print(Fruit.PEAR.value)

# enums are hashable - can be used as keys
myFruits = {}
myFruits[Fruit.BANANA] = "Come Mr. Tally-man"
print(myFruits[Fruit.BANANA])
```

    Fruit.APPLE
    <enum 'Fruit'>
    <Fruit.APPLE: 1>
    APPLE 1
    5
    Come Mr. Tally-man


### Class - Strings


```python
#customize string representations of objects
class Person():
    def __init__(self):
        self.fname = "Joe"
        self.lname = "Marini"
        self.age = 25

    # use __repr__ to create a string useful for debugging
    def __repr__(self):
        return "<Person Class - fname:{0}, lname:{1}, age{2}>".format(self.fname, self.lname, self.age)

    # use str for a more human-readable string
    def __str__(self):
        return "Person ({0} {1} is {2})".format(self.fname, self.lname, self.age)

    # use bytes to convert the informal string to a bytes object
    def __bytes__(self):
        return bytes(self.__str__().encode('utf-8'))



# create a new Person object
cls1 = Person()

# use different Python functions to convert it to a string
print(repr(cls1))
print(str(cls1))
print("Formatted: {0}".format(cls1))
print(bytes(cls1))

```

    <Person Class - fname:Joe, lname:Marini, age25>
    Person (Joe Marini is 25)
    Formatted: Person (Joe Marini is 25)
    b'Person (Joe Marini is 25)'


### Class - Class Attribute Functions

|          Attribute Function         	|    Called When    	| Description                                                            	|
|:-----------------------------------:	|:-----------------:	|------------------------------------------------------------------------	|
| object.__getattribute__(Self, attr) 	|    object.attr    	| is called every time when a attribute is requested (default behaviour) 	|
|    object.__getattr__(Self, attr)   	|    object.attr    	| is called only when the attribyte  cannot be found on the object       	|
| object.__setattr__(self, attr, val) 	| object.attr = val 	| is called when a attribute is set                                      	|
| object.__delattr__(Self)            	| del object.attr   	| is called when a attribute is deleted                                  	|
| object.__dir__(self)                	| dir(object)       	| when dir(object) is called                                                                       	|


```python
# customize string representations of objects
class myColor():
    def __init__(self):
        self.red = 50
        self.green = 75
        self.blue = 100

    # use getattr to dynamically return a value
    def __getattr__(self, attr):
        if attr == "rgbcolor":
            return (self.red, self.green, self.blue)
        elif attr == "hexcolor":
            return "#{0:02x}{1:02x}{2:02x}".format(self.red, self.green, self.blue)
        else:
            raise AttributeError

    # use setattr to dynamically return a value
    def __setattr__(self, attr, val):
        if attr == "rgbcolor":
            self.red = val[0]
            self.green = val[1]
            self.blue = val[2]
        else:
            super().__setattr__(attr, val)

    # use dir to list the available properties
    def __dir__(self):
        return ("red", "green", "blue", "rgbolor", "hexcolor")

# create an instance of myColor
cls1 = myColor()
# print the value of a computed attribute
print(cls1.rgbcolor)
print(cls1.hexcolor)

# set the value of a computed attribute
cls1.rgbcolor = (125, 200, 86)
print("\nAfter changing {0}".format(cls1.rgbcolor))
print(cls1.hexcolor)

# access a regular attribute
print(cls1.red)

# list the available attributes
print("dir - list all attributes {0}".format(dir(cls1)))
```

    (50, 75, 100)
    #324b64
    
    After changing (125, 200, 86)
    #7dc856
    125
    dir - list all attributes ['blue', 'green', 'hexcolor', 'red', 'rgbolor']


***
### Class - Comparision


```python
# Use special methods to compare objects to each other

class Employee():
    def __init__(self, fname, lname, level, yrsService):
        self.fname = fname
        self.lname = lname
        self.level = level
        self.seniority = yrsService

    # implement comparison functions by emp level
    def __ge__(self, other):
        if self.level == other.level:
            return self.seniority >= other.seniority
        return self.level >= other.level

    def __gt__(self, other):
        if self.level == other.level:
            return self.seniority > other.seniority
        return self.level > other.level

    def __lt__(self, other):
        if self.level == other.level:
            return self.seniority < other.seniority
        return self.level < other.level

    def __le__(self, other):
        if self.level == other.level:
            return self.seniority <= other.seniority
        return self.level <= other.level

    def __eq__(self, other):
        return self.level == other.level

    
# define some employees
dept = []
dept.append(Employee("Tim", "Sims", 5, 9))
dept.append(Employee("John", "Doe", 4, 12))
dept.append(Employee("Jane", "Smith", 6, 6))
dept.append(Employee("Rebecca", "Robinson", 5, 13))
dept.append(Employee("Tyler", "Durden", 5, 12))

# Who's more senior?
print(bool(dept[0] > dept[2]))
print(bool(dept[4] < dept[3]))

# sort the items
emps = sorted(dept)
print("Employees sorted by level, seniority : {0}".format([emp.fname for emp in emps]))
```

    False
    True
    Employees sorted by level, seniority : ['John', 'Tim', 'Tyler', 'Rebecca', 'Jane']


___
### Logging

|Message Level | Logging API| Description
|--- |--- |--- |
|DEBUG | logging.debug() | Diagnostic information useful for debugging
|INFO | logging.info() | General information about program execution results
|WARNING | logging.warning() |  Something unexpected, or an approaching problem
|ERROR | logging.error() |  Unable to perform a specific operation due to problem
|CRITICAL | logging.critical() | Program may not be able to continue, serious error

* By default only level after warning will be logged but it can be altered by specifing `logging.basicConfig(level=logging.DEBUG)`


```python
import logging
# Use basicConfig to configure logging
# this is only executed once, subsequent calls to
# basicConfig will have no effect
logging.basicConfig(level=logging.DEBUG,
                    filemode="w",
                    filename="output.log")

# Try out each of the log levels
logging.debug("This is a debug-level log message")
logging.info("This is an info-level log message")
logging.warning("This is a warning-level message")
logging.error("This is an error-level message")
logging.critical("This is a critical-level message")

# Output formatted string to the log
logging.info("Here's a {} variable and an int: {}".format("string", 10))
```

***
### Comprehensions - List


```python
# define two lists of numbers
evens = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
odds = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]

# Perform a mapping and filter function on a list
evenSquared = list(
    map(lambda e: e**2, filter(lambda e: e > 4 and e < 16, evens)))
print("Without List comprehension {0}".format(evenSquared))

# Limit the items operated on with a predicate condition
oddSquared = [e ** 2 for e in odds if e > 3 and e < 17]
print("With List comprehension {0}".format(oddSquared))
```

    Without List comprehension [36, 64, 100, 144, 196]
    WIth List comprehension [25, 49, 81, 121, 169, 225]


***
### Comprehensions - Dict


```python
# define a list of temperature values
ctemps = [0, 12, 34, 100]

# Use a comprehension to build a dictionary
tempDict = {t: (t * 9/5) + 32 for t in ctemps if t < 100}
print(tempDict)
print(tempDict[12])

# Merge two dictionaries with a comprehension
team1 = {"Jones": 24, "Jameson": 18, "Smith": 58, "Burns": 7}
team2 = {"White": 12, "Macke": 88, "Perce": 4}
newTeam = {k: v for team in (team1, team2) for k, v in team.items()}
print(newTeam)
```

    {0: 32.0, 12: 53.6, 34: 93.2}
    53.6
    {'Jones': 24, 'Jameson': 18, 'Smith': 58, 'Burns': 7, 'White': 12, 'Macke': 88, 'Perce': 4}


***
### Comprehensions - Set


```python
# define a list of temperature data points
ctemps = [5, 10, 12, 14, 10, 23, 41, 30, 12, 24, 12, 18, 29]

# build a set of unique Fahrenheit temperatures
ftemps1 = [(t * 9/5) + 32 for t in ctemps]
ftemps2 = {(t * 9/5) + 32 for t in ctemps}
print(ftemps1)
print(ftemps2)

# build a set from an input source
sTemp = "The quick brown fox jumped over the lazy dog"
chars = {c.upper() for c in sTemp if not c.isspace()}
print(chars)
```

    [41.0, 50.0, 53.6, 57.2, 50.0, 73.4, 105.8, 86.0, 53.6, 75.2, 53.6, 64.4, 84.2]
    {64.4, 73.4, 41.0, 105.8, 75.2, 50.0, 84.2, 53.6, 86.0, 57.2}
    {'R', 'N', 'V', 'F', 'T', 'X', 'E', 'O', 'Y', 'Z', 'J', 'A', 'P', 'Q', 'K', 'G', 'C', 'B', 'M', 'H', 'W', 'U', 'I', 'L', 'D'}



```python

```
