# 条件查询

/*
 语法
    select 查询列表
    from 表名
    where 筛选条件;

 分类：
    一、按条件表达式筛选
        条件运算符： > < = != <> >= <=
    二、按逻辑表达式筛选
        逻辑运算符：&& || !
                  and or not
    三、模糊查询
        like
        between and
        in
        is null
 */

# 一、条件表达式筛选
#查询工资大于一万二的员工讯息
SELECT *
FROM employees
WHERE salary >= 12000;

#查询部门编号不等于90号的员工名和部门编号
SELECT CONCAT(last_name, ',', first_name) AS 姓名, department_id
FROM employees
WHERE department_id != 90;

# 二、按逻辑表达式查询
# 查询工资在一万到两万之间的员工名，工资以及奖金
SELECT CONCAT(last_name, ',', first_name) AS 姓名, salary, commission_pct
FROM employees
WHERE salary >= 10000
  AND salary <= 20000;

# 查询部门编号不在90到100之间，或者工资高于15000的员工信息
SELECT *
FROM employees
WHERE NOT (department_id >= 90 AND department_id <= 110)
   OR salary > 15000;

# 模糊查询


# like
# 与通配符共同使用
# %任意多个字符，包含0个
# _任意单个字符
# 查询员工名字包含a的员工信息
SELECT *
FROM employees
WHERE last_name LIKE '%a%';

# 查询员工名字中第三个字符为e，第五个字符为a的员工名和工资
SELECT last_name, salary
FROM employees
WHERE last_name LIKE '__n_l%';

# 查询员工第二个名字是下划线的员工名
SELECT last_name
FROM employees
WHERE last_name LIKE '_\_%';

SELECT last_name
FROM employees
WHERE last_name LIKE '_$_%' ESCAPE '$';

# between and
# 查询员工编号100到120之间的信息
# 包含临界值
# 顺序不能换
SELECT *
FROM employees
WHERE employee_id BETWEEN 100 AND 120;


# in
# 查询工种编号是IT_PROG,AD_VP,AD_PRES中的一个员工名和编号
SELECT last_name, job_id
FROM employees
WHERE job_id = 'IT_PROG'
   OR job_id = 'AD_VP'
   OR job_id = 'AD_PRES';

SELECT last_name, job_id
FROM employees
WHERE job_id IN ('IT_PROG', 'AD_VP', 'AD_PRES');

# 查询没有奖金的员工的名字和奖金率
SELECT last_name, commission_pct
FROM employees
WHERE commission_pct IS NULL;

# 安全等于  <=>
SELECT last_name, commission_pct
FROM employees
WHERE commission_pct <=> NULL;
