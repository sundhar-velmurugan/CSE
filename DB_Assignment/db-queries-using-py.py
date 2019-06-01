#!/usr/bin/python3

import sqlite3
from tabulate import tabulate

def create():
	c.execute('''CREATE TABLE Dept
				(Deptno INT ,
				 Dname VARCHAR(50), 
				 Loc VARCHAR(25), 
				 PRIMARY KEY(Deptno))''')
	c.execute('''CREATE TABLE Employee
				(Empno VARCHAR(5), 
				Ename VARCHAR(25), 
				Job VARCHAR(30), 
				Managerid INT, 
				JoinDate DATE, 
				Salary FLOAT(10,2), 
				Commision FLOAT(6,2), 
				Deptno INT, 
				PRIMARY KEY(Empno), 
				FOREIGN KEY(Deptno) REFERENCES Dept(Deptno) )''')

def insert():
	c.execute('''INSERT INTO Dept VALUES 
				(10, 'Administration', 'New York')''')
	c.execute('''INSERT INTO Dept VALUES 
				(15, 'R&D', 'Chicago')''')
	c.execute('''INSERT INTO Dept VALUES 
				(20, 'Sales', 'Boston')''')
	c.execute('''INSERT INTO Dept VALUES 
				(25, 'Public Relations', 'Los Angeles')''')
	c.execute('''INSERT INTO Employee VALUES 
				('e1', 'Allen', 'Sales Executive', 1, '2015-10-03', 5000, 500, 20)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e2', 'Blake', 'Manager', 1, '1980-07-10', 10000, 700, 10)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e3', 'Ram', 'Devloper', 2, '2015-05-01', 5500, 500, 15)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e4', 'Sundhar', 'Manager', 2, '2015-12-31', 7000, 700, 10)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e5', 'Jack', 'Tester', 2, '2017-01-17', 4500, 500, 15)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e6', 'Murdock', 'Sales Executive', 1, '2016-04-04', 2800, 500, 20)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e7', 'Karl', 'Engineer', 2, '1978-09-27', 3000, 500, 15)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e8', 'Murphy', 'Sales Rep', 1, '2015-08-11', 3500, 500, 20)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e9', 'Kathy', 'Sales Rep', 1, '2014-01-10', 4500, 500, 20)''')
	c.execute('''INSERT INTO Employee VALUES 
				('e10', 'Celine', 'Sales Rep', 1, '2015-09-21', 3300, 500, 20)''')

def result():
	table=c.fetchall()
	print('='*70)
	print(tabulate(table))
	print('='*70)

def display():
	print('Department Table'.center(60, '-'))
	c.execute('SELECT * FROM Dept')
	result()	
	print('Employee Table'.center(60, '-'))
	c.execute('SELECT * FROM Employee')
	result()	

def query():
	print('1, Display details of All Managers')
	c.execute('SELECT * FROM Employee WHERE Job==\'Manager\'')
	result()
	print('2, Employees joined before 1981')
	c.execute('SELECT * FROM Employee WHERE DATE(JoinDate)<=\'1981-01-01\'')
	result()
	print('3, Empno, Ename, Salary, Daily Salary of all employees in ascending order')
	c.execute('SELECT Empno, Ename, Salary, Salary/30 FROM Employee ORDER BY Salary')
	result()
	print('4, Employees joined in 1st may 2015, 31 dec 2015, 3rd oct 2015')
	c.execute('''SELECT * FROM Employee WHERE DATE(JoinDate)==\'2015-05-01\' OR 
			DATE(JoinDate)==\'2015-12-31\' OR DATE(JoinDate)==\'2015-10-03\' 
			ORDER BY JoinDate''')
	result()
	print('5, Ename with len=4 and 3rd character \'r\'')
	c.execute('SELECT * FROM Employee WHERE Ename LIKE \'__r_\'')
	result()
	print('6, Employees in Deptno 20')
	c.execute('Select * FROM Employee WHERE Deptno==20')
	result()
	print('7, Details of department and Employees')
	c.execute('''SELECT d.Deptno, d.Dname, d.Loc, e.Empno, e.Ename FROM Dept as d 
				LEFT OUTER JOIN Employee as e ON e.Deptno==d.Deptno''')
	result()
	print('8, Employees whose salary is more than Ram')
	c.execute('''SELECT * FROM Employee WHERE Salary>(SELECT Salary FROM Employee 
				WHERE Ename==\'Ram\')''')
	result()
	print('9, Employee with same job as Allen')
	c.execute('''SELECT * FROM Employee WHERE Job==(SELECT Job FROM Employee 
				WHERE Ename==\'Allen\')''')
	result()
	print('10, Employees senior to blake working in Chicago or Boston')
	c.execute('''SELECT e.Empno, e.Ename, d.Deptno, d.Dname, d.Loc FROM Dept AS d 
				LEFT OUTER JOIN Employee AS e WHERE e.Deptno==d.Deptno AND 
				e.JoinDate<(SELECT JoinDate FROM Employee WHERE Ename==\'Blake\') 
				AND (d.Loc==\'Chicago\' OR d.Loc==\'Boston\')''')
	result()
	print('11, Highest paid employee in sales dept')
	c.execute('''SELECT * FROM Employee WHERE Salary==(SELECT MAX(Salary) FROM 
				(SELECT * FROM Employee WHERE Deptno==(SELECT Deptno FROM Dept 
				WHERE Dname==\'Sales\')))''')
	result()
	print('12, Total salary given to managers')
	c.execute('SELECT SUM(Salary) FROM Employee WHERE Job==\'Manager\'')
	result()
	print('13, Department with atleast 2 employees working')
	c.execute('''SELECT * FROM Dept WHERE Deptno IN 
				(SELECT Deptno FROM (SELECT COUNT(Empno) AS c, 
				Deptno FROM Employee GROUP BY Deptno) WHERE c>=2)''')
	result()
	print('14, Employee salary>3000 after salary*20%')
	c.execute('SELECT Empno, Ename, Salary FROM Employee WHERE Salary*1.2>3000')
	result()
	print('15, No of employees in each dept if employee count>3')
	c.execute('''SELECT Deptno, c FROM (SELECT COUNT(Empno) AS c, 
				Deptno FROM Employee GROUP BY Deptno) WHERE c>3''')
	result()
	print('16, Names of department where no of employee>3')
	c.execute('''SELECT Dname FROM Dept WHERE Deptno IN 
				(SELECT Deptno FROM (SELECT COUNT(Empno) AS c, 
				Deptno FROM Employee GROUP BY Deptno) WHERE c>3)''')
	result()
	print('17, Employees who joined before their managers')
	c.execute('''SELECT Empno, Ename, JoinDate, Managerid FROM 
				(SELECT * FROM Employee) AS a LEFT OUTER JOIN 
				(SELECT JoinDate AS j, Managerid AS m FROM Employee 
				WHERE Job==\'Manager\') AS b WHERE a.Managerid==b.m 
				AND a.Joindate<b.j''')
	result()
	print('18, Deptno that has no employees')
	c.execute('''SELECT d.Deptno FROM Dept as d LEFT OUTER JOIN Employee as e
				 ON e.Deptno==d.Deptno WHERE e.Deptno is NULL''')
	result()
	print('19, Dept whose avg salary is less than the avg salary of all departments')
	c.execute('''SELECT b.Deptno, b.u FROM (SELECT AVG(s) as t 
				FROM (SELECT AVG(Salary) AS s, Deptno FROM Employee GROUP BY Deptno)) AS a 
				CROSS JOIN (SELECT AVG(Salary) As u, Deptno FROM Employee GROUP BY Deptno) AS b 
				WHERE a.t>b.u''')
	result()
	print('20, Dept 10 employees having greater salary than Allen')
	c.execute('''SELECT * FROM Employee 
				WHERE Salary>(SELECT Salary FROM Employee WHERE Ename==\'Allen\') 
				AND Deptno==10''')
	result()

if __name__=="__main__":
	conn = sqlite3.connect('assignment.db')
	c = conn.cursor()
	create()
	insert()
	display()
	query()
	conn.commit()
	conn.close()
