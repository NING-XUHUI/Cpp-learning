# 分组函数
/*
 用作统计
分类：
 sum avg max min count
 */

SELECT SUM(salary) AS sum
FROM employees;

SELECT AVG(salary)
FROM employees;
SELECT MAX(salary)
FROM employees;
SELECT MIN(salary)
FROM employees;
SELECT COUNT(salary)
FROM employees;

# 2.参数支持哪些类型
SELECT SUM(last_name)
FROM employees;

SELECT COUNT(commission_pct)
FROM employees;

# 搭配DESTINCT
SELECT COUNT(*)
FROM employees;

SELECT COUNT(1)
FROM employees;

#  效率
# myisam存储引擎下 *的效率高
# innodb         1和*差不多，但比字段查询效率高

# 和分组函数查询使用的限制
# 和分组函数一同查询的字段一般是group by后的字段

# SELECT AVG(salary),employee_id FROM employees;

# 测试

# 查询公司员工工资的最大值，最小值，平均值和总和
#最大值
SELECT MAX(salary)
FROM employees;

#最小值
SELECT MIN(salary)
FROM employees;

#平均值
SELECT AVG(salary)
FROM employees;

#总和
SELECT SUM(salary)
FROM employees;

#查询员工最大入职时间与最小入职时间的相差天数
SELECT DATEDIFF(MAX(hiredate), MIN(hiredate))
FROM employees;

# 查询部门编号为90的员工个数
SELECT COUNT(*)
FROM employees
WHERE department_id = 90;