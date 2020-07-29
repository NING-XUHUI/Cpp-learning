# 查询员工编号为176的员工的姓名和部门号和年薪
SELECT last_name,department_id,salary*12*(1+IFNULL(commission_pct,0)) AS 年薪
FROM employees
WHERE employee_id <=> 176;

# 查询没有奖金且工资小于一万八的salary和名
SELECT salary,last_name
FROM employees
WHERE commission_pct <=> NULL AND salary <= 18000;

#查询job不为IT或者工资为一万二的员工信息
SELECT *
FROM employees
WHERE job_id NOT LIKE 'IT%' OR salary = 12000;

# 查询部门表中设计了哪些位置编号
desc departments;

SELECT DISTINCT location_id
FROM departments;

/*
 select * from employees;和select * from employees commission_pct like '%%' and last_name like '%%'是否一样
 */

 SELECT *
FROM employees;

SELECT *
FROM employees
WHERE commission_pct LIKE '%%' OR last_name like '%%';
