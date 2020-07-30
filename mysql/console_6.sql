# 分组查询

# 查询每个部门的平均工资

# 查询每个工种的最高工资
SELECT MAX(salary),job_id
FROM employees
GROUP BY job_id;

# 查询每个位置上的部门个数
SELECT COUNT(*),location_id
FROM departments
GROUP BY location_id;

# 添加筛选条件
# 查询邮箱中包含a字符的，每个部门的平均工资

SELECT AVG(salary),department_id
FROM employees
WHERE email like '%a%'
GROUP BY department_id;

# 查询有奖金的每个领导手下员工的最高工资
SELECT MAX(salary),manager_id
FROM employees
WHERE commission_pct IS NOT NULL
GROUP BY manager_id;

# 添加复杂的筛选条件
# 查询哪个部门的员工个数大于2
SELECT COUNT(*),department_id
FROM employees
GROUP BY department_id
HAVING COUNT(*) > 2;

# 查询每个工种有奖金的员工的最大工资并且大于一万二
SELECT MAX(salary),job_id
FROM employees
WHERE commission_pct IS NOT NULL
GROUP BY job_id
HAVING MAX(salary) > 12000;


# 查询领导编号大于102的每个领导手下的最低工资大于五千的领导编号及其最低工资
SELECT MIN(salary),manager_id
FROM employees
WHERE manager_id > 102
GROUP BY manager_id
HAVING MIN(salary) > 5000;

# 按表达式或函数分组
# 按员工姓名的长度分组，查询每一组的员工个数，筛选个数大于五的

SELECT COUNT(*),LENGTH(last_name)
FROM employees
GROUP BY LENGTH(last_name)
HAVING COUNT(*) > 5;


# 多个字段分组
# 查询每个部门每个工种的员工平均工资
SELECT AVG(salary),department_id,job_id
FROM employees
GROUP BY department_id, job_id;

# 查询每个部门每个工种的员工平均工资,并排序
SELECT AVG(salary),department_id,job_id
FROM employees
WHERE department_id IS NOT NULL
GROUP BY  job_id,department_id
HAVING AVG(salary) > 10000
ORDER BY AVG(salary) DESC;

# 测试

# 查询个job的员工工资的最大值，最小值，平均值，总和，按job升序
SELECT MAX(salary),MIN(salary),AVG(salary),SUM(salary),job_id
FROM employees
GROUP BY job_id
ORDER BY job_id;

# 查询员工的最高工资和最低工资的差距
SELECT (MAX(salary) - MIN(salary)) AS DIFF
FROM employees;

# 查询各个管理者手下的员工的最低工资，其中最低工资不能低于6000，没有管理这个员工不计算在内
SELECT MIN(salary),manager_id
FROM employees
WHERE manager_id IS NOT NULL
GROUP BY manager_id
HAVING MIN(salary) >= 6000;

# 查询所有部门和编号，员工数量和工资平均值，按平均工资降序
SELECT COUNT(*),AVG(salary),department_id
FROM employees
GROUP BY department_id
ORDER BY AVG(salary) DESC ;

# 选择具有各个job_id的人数
SELECT COUNT(*),job_id
FROM employees
GROUP BY job_id;