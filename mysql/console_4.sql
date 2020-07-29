# 常见函数

/**
  功能：
    类似java的方法，将一组逻辑封装
    隐藏了实现细节，提高代码的重用性
  调用：select()函数名（实参列表）
  特点：叫什么，干什么
  分类
        单行函数
        分组函数
 */

# 字符函数
# length获取参数值的 字节 个数
SELECT LENGTH('张三丰hhh');

# concat
SELECT CONCAT(last_name, first_name)
FROM employees;

# upper,lower
SELECT UPPER('john');

# 姓大写名小写后拼接
SELECT CONCAT(LOWER(last_name), UPPER(first_name))
FROM employees;

# substr  substring
# 指定索引截取
SELECT SUBSTR('李莫愁爱上了陆展元', 7);

# 指定索引与长度
SELECT SUBSTR('李莫愁爱上了陆展元', 1, 3);

# 姓名中手字符大写，其他小写后拼接
SELECT CONCAT(UPPER(SUBSTR(last_name, 1, 1)), '_', SUBSTR(last_name, 2))
FROM employees;

SELECT last_name
FROM employees;

# instr  返回字串第一次出现的索引，找不到返回0
SELECT INSTR('杨不悔爱上了应留下', '应留下') AS op
FROM employees;

# trim
SELECT TRIM('      张翠山    ') AS op;
SELECT TRIM('a' FROM 'aaaaaaa张aaa翠山aaaaa') AS op;

# lpad 用指定字符实现左填充指定长度
SELECT LPAD('殷素素', 10, '*') as op;

# rpad 右
SELECT RPAD('殷素素', 10, '*') as op;


# replace 替换
SELECT REPLACE('张无忌爱上了周芷若周芷若周芷若周芷若', '周芷若', '赵敏') as op;



# 数学函数

# round 四舍五入
SELECT ROUND(-1.45);
SELECT ROUND(1.567, 2);

# ceil向上取整
SELECT CEIL(1.3);
SELECT CEIL(-1.3);

# floor 向下取整
SELECT FLOOR(2.7);

# truncate截断
SELECT TRUNCATE(1.65, 1);

# mod 取余
SELECT MOD(10, 3);


# 日期函数

# now 返回当前系统日期与时间

SELECT NOW();

# curdate 返回日期无时间
SELECT CURDATE();

# curtime 无日期，返回时间
SELECT CURTIME();

# 获取指定的部分，年月日时分秒
SELECT YEAR(NOW()) 年;
SELECT YEAR('1998-01-01');

SELECT YEAR(hiredate)
FROM employees;

# 查询入职日期为1992-4-3的员工信息
SELECT *
FROM employees
WHERE hiredate = '1992-4-3';

# STR_TO_DATE字符转日期
SELECT STR_TO_DATE('1998-3-2', '%Y-%c-%d');

# DATE_FORMAT日期转字符
SELECT DATE_FORMAT(NOW(), '%Y年%m月%d日');

# 查询有奖金的员工名和入职日期
SELECT last_name, DATE_FORMAT(hiredate, '%m月/%d日 %Y年')
FROM employees
WHERE commission_pct IS NOT NULL;

# 其他函数
SELECT VERSION();
SELECT DATABASE();
SELECT USER();

# 流程控制函数
# if:if - else

SELECT IF(10 > 5, 'da', 'xiao');

SELECT last_name, commission_pct, IF(commission_pct IS NULL, '无', '有') 备注
FROM employees;

# case函数:switch case
# case 要判断的语句
# when 常量1 then ...
# when 常量2 then ...

# 查询员工的工资，要求
# 部门=40，显示工资为1。1倍
#      30        1。2
#      50        1。3

SELECT salary  AS 原始工资,
       department_id,
       CASE department_id
           WHEN 30
               THEN salary * 1.1
           WHEN 40
               THEN salary * 1.2
           WHEN 50
               THEN salary * 1.5
           ELSE salary
           END AS 新工资
FROM employees;

# case 类似多重if

# 如果工资大于20000，显示A。。。。。。。
SELECT last_name,
       salary,
       case
           WHEN salary > 20000 THEN 'A'
           WHEN salary > 15000 THEN 'B'
           WHEN salary > 10000 THEN 'C'
           WHEN salary > 5000 THEN 'D'
        ELSE 'F'
        END AS 等级
FROM employees;

### 习题

# 显示系统时间（日期+时间）
SELECT NOW();

# 查询员工号，姓名，工资，以及工资提高百分之二十的结果
SELECT employee_id,last_name,salary,salary * 1.2 AS 'new salary'
FROM employees;

# 将员工的姓名按首字母排序，并写出姓名的长度
SELECT SUBSTR(last_name,1,1) AS fc,LENGTH(last_name) AS length
FROM employees
ORDER BY fc;

# 做一个查询，产生下面的结果

SELECT CONCAT(last_name,' earns ',salary,' monthly but wants ',salary*3) AS 'Dream Salary'
FROM employees;

#
SELECT last_name,job_id,
       case job_id
WHEN 'AD_PRES' THEN 'A'
WHEN 'ST_MAN' THEN 'B'
WHEN 'IT_PROG' THEN 'C'
END AS 'grade'
FROM employees;