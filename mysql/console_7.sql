# 连接查询
# 多表查询
# 笛卡尔乘积现象

# 等值连接
SELECT name,boyName FROM beauty, boys
WHERE beauty.boyfriend_id=boys.id;

# 查询员工名和对应的部门名
SELECT last_name,department_name
FROM employees,departments
WHERE employees.department_id=departments.department_id;

# 查询员工名，工种号，工种名
SELECT last_name,employees.job_id,job_title
FROM employees,jobs
WHERE employees.job_id=jobs.job_id;

# 加筛选

# 查询有奖金的员工名和部门名

SELECT last_name,d.department_id
FROM employees e,departments d
WHERE e.commission_pct IS NOT NULL AND e.department_id=d.department_id;

# 查询城市中第二个字符为o的部门名和城市名
SELECT l.city,d.department_id
FROM locations l,departments d
WHERE l.city LIKE '_o%' AND l.location_id=d.location_id;

# 加分组
# 查询每个城市的部门个数
SELECT COUNT(*),l.city
FROM departments d,locations l
WHERE d.location_id = l.location_id
GROUP BY city;

# 查询有奖金的每个部门的部门名和部门领导编号和该部门最低工资
SELECT department_name,e.manager_id,MIN(salary)
FROM departments d,employees e
WHERE commission_pct IS NOT NULL
AND d.department_id = e.department_id
GROUP BY department_name, d.manager_id;

# 查询每个工种的工种名和员工的个数，降序
SELECT job_title,COUNT(*)
FROM jobs,employees
WHERE jobs.job_id = employees.job_id
GROUP BY jobs.job_title
ORDER BY COUNT(*) DESC ;

# 三表连接
# 查询员工名，部门名和所在的城市
SELECT last_name,department_name,city
FROM employees e,departments d,locations l
WHERE e.department_id = d.department_id AND d.location_id = l.location_id;

CREATE TABLE job_grade
(
    grade_level VARCHAR(3),
    lowest_sal INT,
    highest_sal INT
);

INSERT INTO job_grade
VALUES ('A',1000,2999);

INSERT INTO job_grade
VALUES ('B',3000,5999);

INSERT INTO job_grade
VALUES ('C',6000,9999);

INSERT INTO job_grade
VALUES ('D',10000,14999);

INSERT INTO job_grade
VALUES ('E',15000,24999);

INSERT INTO job_grade
VALUES ('F',25000,40000);

SELECT * FROM job_grade;
# 非等值连接

# 查询员工的工资和工资级别
SELECT salary,grade_level
FROM employees e,job_grade g
WHERE salary BETWEEN g.lowest_sal AND g.highest_sal;

# 查询工资级别中的最高最低工资
SELECT MAX(salary),MIN(salary),grade_level
FROM employees e,job_grade g
WHERE salary BETWEEN g.lowest_sal AND g.highest_sal
GROUP BY grade_level;


# 自连接
# 查询员工名和上级名称
SELECT e1.employee_id,e1.last_name,e2.manager_id,e2.last_name
FROM employees e1,employees e2
WHERE e1.manager_id = e2.employee_id;


# 测试
# 显示员工表的最大工资，工资平均值
SELECT MAX(salary),AVg(salary)
FROM employees;

# 查询员工表的id，工种id，姓名 按部门id降序，salary升序
SELECT employee_id,job_id,last_name
FROM employees
ORDER BY department_id DESC ,salary ASC;

# 查询员工表的jobid中包含a和e的，并且a在e的前面
SELECT DISTINCT job_id
FROM employees
WHERE job_id LIKE '%a%e%';

# 显示当前日期，去前后空格截取子字符串的函数
SELECT NOW();
SELECT TRIM('   a   ' from ' ');

select substr(last_name,startIndex);
select substr(str,startIndex,length);