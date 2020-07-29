#进阶1：基础查询
/*
 语法：
 select 查询列表

 类似于：System.out.println(打印东西);

 特点：
 1 查询列表可以是：表中的字段，常量值，表达式，函数
 2 结果是虚拟表格
 */

# 1 查询表中的单个字段
SELECT last_name
FROM employees;

# 2.查询表中的多个字段
SELECT last_name, salary, email
FROM employees;

# 3.查询所有字段
SELECT employee_id, first_name, last_name, phone_number
FROM employees;

#或
SELECT *
FROM employees;

# 4 查询常量值
SELECT 100;
SELECT 'john';

# 5 查询表达式
SELECT 100 - 1;

# 6 查询函数
SELECT VERSION();

# 7.起别名

# 方式一
SELECT 100 % 98 AS 结果;
SELECT last_name AS 姓, first_name AS 名
FROM employees;

# 方式二
SELECT last_name 姓, first_name 名
FROM employees;

# 案例
SELECT salary AS 'out put'
FROM employees;

# 8.去重
SELECT DISTINCT department_id
FROM employees;

# +的作用
/*
 mysql中+仅仅是运算符
 select 100+89;两个操作数都是数值型，做加法运算
 select '123'+89;其中一方为字符型，将字符型转换为数值型，若转换成功，继续加法运算，失败则转换为0
 select 'john'+90;
 select NULL+89;只要其中一个为null，则结果为null
 */
# 案例：员工名和姓连接
SELECT CONCAT('a', 'b', 'c') AS 结果;

SELECT CONCAT(last_name, ' ', first_name) AS 姓名
FROM employees;

# 显示出全部列，各个列用逗号连接，列头为OUT_PUT
SELECT CONCAT(first_name, ',', last_name,',',IFNULL(commission_pct,0)) AS out_out
FROM employees;