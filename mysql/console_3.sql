# 排序查询

/*
 语法：
    SELECT
    FROM
    WHERE
    ORDER BY [asc|desc]
 asc升序
 desc降序
 默认升序
 */

# 查询员工信息，要求工资从高到底排序
SELECT *
FROM employees
ORDER BY salary ASC;

# 查询部门编号>=90的员工信息，按入职时间先后进行排序
SELECT *
FROM employees
WHERE department_id >= 90
ORDER BY hiredate ASC;

# 按表达式排序
# 按年薪高低显示信息和年薪

SELECT *, salary * 12 * (1 + IFNULL(commission_pct, 0)) AS 年薪
FROM employees
ORDER BY 年薪 DESC;

# 按姓名的长度显示姓名和工资
SELECT LENGTH(last_name), last_name, salary
FROM employees
ORDER BY LENGTH(last_name) DESC;

# 要求先工资排序，再编号排序
SELECT *
FROM employees
ORDER BY salary ASC ,employee_id DESC ;

# 查询员工的姓名和部门号和年薪，按年薪降序，姓名升序
SELECT CONCAT(last_name,' ',first_name) AS name, salary*12*(1+IFNULL(commission_pct,0)) AS 年薪
FROM employees
ORDER BY 年薪 DESC , name ASC ;

# 选择工资不再8000-17000的员工的姓名和工资，工资降序
SELECT last_name,salary
FROM employees
WHERE NOT (salary >= 8000 && salary <=17000)
# NOT BETWEEN 8000 AND 17000
ORDER BY salary DESC;

# 查询邮箱中包含e的员工信息，先按邮箱字节数降序，再按部门号升序
SELECT *
FROM employees
WHERE email LIKE '%e%'
ORDER BY LENGTH(email) DESC ,department_id ASC ;