
SET PAGESIZE 44
purge RECYCLEBIN;
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name       varchar2(20),    -- �̸�
    gno          number,           -- ��ȣ (�μ���ȣ, �����ȣ) >> Primary Key(PK)//��Ű
    sal           number            -- �޿�
);

DROP TABLE tab02;
CREATE TABLE tab02(
    gno          number,           --��ȣ >> Foreign Key(FK) // �ܷ�Ű
    grade       varchar2(20)            --��� ( 1���, 2���, A��, B��)
);

insert into tab01 values( '�̼���', 1, 100);
insert into tab01 values( '���߱�', 2, 200);
insert into tab01 values( '�̼���', 2, 300);
insert into tab01 values( '������', 1, 400);

insert into tab02 values( 1, '����');
insert into tab02 values( 2, '�λ�');
insert into tab02 values( 3, 'û��');
*/
/*
-- ������ �Ǹ�
-- 2�� �̻��� ���̺��� ���� ���� ���踦 ���� �� ������ ������ ���̽�
-- ���� ����(cross join) = ī�׽þ� ��
-- �������� ��ü�����δ� ������� �ʴ´�. (�����)
-- ���̺� row ������ 1000�� * 1000�� ��� ���ϱ޼����� �����Ͱ� ����(�޸𸮰� ���� �Ұ�)
-- ���� ���ҵ� ���� �Ұ�
select * from tab01 cross join tab02; -- �����
select * from tab01, tab02; -- ������

-- �������ΰ�  ���� ���� >> �����
--� ������ 2���� ���̺� �ݵ�� ��ġ�ϴ� �ʵ�(��)�� �־�� �Ѵ�.

-- T-SQL����
select * from tab01, tab02 where tab01. gno = tab02.gno; 

-- �޸� ��ſ� inner join, where��ſ� on >> ���� ���� == � ����
-- ANSI SQL ���� ����(ǥ�� ����)
select * from tab01 inner join tab02 on tab01. gno = tab02.gno;
-- inner�� ������ �� �ִ�.
select * from tab01 join tab02 on tab01. gno = tab02.gno;

-- ����Ǵ� �ʵ� �˾Ƽ� �������ش�. >> �ڿ� ����
select * from tab01 natural join tab02;
--�ڿ������� ���׷��̵� ���� >> �ڿ����� >> using ����
-- ������ �� �ִ� �ʵ���� �Ѱ� �̻��� �� ����Ѵ�. 
--�ڿ����λ� ��ġ�� �κ��� 2�� �̻��� �� ������� �ʿ伺 ������ using���� ���
select * from tab01 join tab02 using(gno);
*/
/*
--���̺� ���� ��Ī�� ����� �� �ִ�. ( ����ϴ°� ��κ��̴�.)
-- [s1, s2] [s, t] [t1, t2]
select * from tab01  t1, tab02 t2 where t1. gno = t2.gno; 
select * from tab01  t1 inner join tab02 t2 on t1. gno = t2.gno; 

-- �����ؼ� ����ϴ� �ڵ�( ��°��� ����)
select * 
from tab01  t1, tab02 t2 
where t1. gno = t2.gno and ROWNUM <= 2;

-- �޿��� 200�̻��� �е��� ������ ����ΰ� ?
select * 
from tab01  t1, tab02 t2 
where t1. gno = t2.gno -- ���� ����
    and t1.sal > 200; -- �Ϲ� ����
-- ture and false >> false�� ���� �� �������� �߸� �ؼ����� �� ��.

-- �� ���̺��� �λ� ����� �����Դϱ�?
select name
from tab01  t1, tab02 t2 
where t1.gno = t2.gno -- ���� ����
    and t2.grade = '�λ�';
*/

-- ����ΰ� ��� �Ǵ°��� �� ����
-- �� ���� : ������� �ƴ� ������ �� �����̴�.
--                      ��Ұ��踦 ���� ����
--                      a >= 100 and a <= 200
--                      between
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name       varchar2(20),    -- �̸�
    gno          number,           -- ��ȣ (�μ���ȣ, �����ȣ) >> Primary Key(PK)//��Ű
    sal           number            -- �޿�
);

DROP TABLE tab02;
CREATE TABLE tab02(
    grade       varchar2(20),            --��� ( 1���, 2���, A��, B��)
    emin        number,
    emax        number
);
insert into tab01 values( '�̼���', 1, 100);
insert into tab01 values( '���߱�', 2, 200);
insert into tab01 values( '�̼���', 2, 300);
insert into tab01 values( '������', 1, 400);

insert into tab02 values(  '1���',100,200);
insert into tab02 values(  '2���',201,300);
insert into tab02 values(  '3���',301,400);
insert into tab02 values(  '4���',401,500);

select * from tab01 t1, tab02 t2
where sal*1.2 >= emin and sal*1.2 <= emax;

select * from tab01 t1, tab02 t2
where sal between emin and emax;
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    id       number,    -- PK(�����ȣ)
    name          varchar2(20),           
    mgr           number            -- FK(�����ȣ)
);
-- ��������
insert into tab01 values( 1, '�̼���', NULL); -- �����
insert into tab01 values( 2, '���߱�', 1); -- ����
insert into tab01 values( 3, '������', 2); -- ����
insert into tab01 values( 4, 'ȫ�浿', 1); -- ����

select t1.id, t1.name,t1.mgr, t2.id,t2.name ����̸�,t2.mgr 
from tab01 t1, tab01 t2 -- ������ ���̺��� ���� �����ϱ� ���� ���(� ���� ����)
where t1.mgr = t2.id;
*/

--�ܺ�����(outer join)
-- where A = B(+)
-- ���� ���̺��� ��� ����� ������ �� �������̺��� ����Ÿ ��Ī
-- where A(+) = B
-- �������� �ݴ� ����
/*
DROP TABLE tab01;
DROP TABLE tab02;

CREATE TABLE tab01(
    id       number,    -- PK(�����ȣ)
    name          varchar2(20)           
);
CREATE TABLE tab02(
    id       number,    -- FK(�����ȣ)
    age           number      
);

insert into tab01 (ID,name) values( 1, 'tiger1');
insert into tab01 (ID,name) values( 2, 'tiger2');
insert into tab01 (ID,name) values( 3, 'tiger3');
insert into tab01 (ID,name) values( 4, 'tiger4');
insert into tab01 (ID,name) values( 5, 'tiger5');

insert into tab02 (ID,age) values( 3, 30);
insert into tab02 (ID,age) values( 4, 40);
insert into tab02 (ID,age) values( 5, 50);
insert into tab02 (ID,age) values( 6, 60);
insert into tab02 (ID,age) values( 7, 70);

-- left outer join
-- a   result   b
-- o      o       x
select *
from tab01 , tab02
where tab01.id = tab02.id(+); -- where tab01.id(+) = tab02.id;

select *
from tab01
left join tab02 using(id); -- right join tab02 using(id);

-- a   result   b
-- o      o       o
select *
from tab01
full join tab02 using(id);

-- a   result   b
-- o      x       x
select * from tab01
left join tab02
on tab01.id = tab02.id
where tab02.id is null;

-- a   result   b
-- o      x       o
select * from tab01
full join tab02
on tab01.id = tab02.id
where 
    tab01.id is null or
    tab02.id is null;

--���� ���� ( on, exists)�� ����� ����
-- 1:n�� ����
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    id                number,    -- PK(�����ȣ)
    name          varchar2(20),
    dept            number
);
DROP TABLE tab02;
CREATE TABLE tab02(
    dept            number,
    name varchar2(20)
);
insert into tab01  values( 10, 'ȫ�浿1',1);
insert into tab01 values( 20, 'ȫ�浿2',1);
insert into tab01 values( 30, 'ȫ�浿3',2);
insert into tab01 values( 40, 'ȫ�浿4',2);

insert into tab02 values( 1, '�İ�');
insert into tab02 values( 2, '�濵');
insert into tab02 values( 3, 'ü��');

-- ex1)
select * from tab02 where dept in (1,1,1,2,2,2,3,3,3);

-- ex2)
select *
from tab01, tab02
where tab01.dept = tab02.dept;

-- ex3)
select distinct(tab02.name)
from tab01, tab02
where tab01.dept = tab02.dept;

-- ex4)
select distinct(b.name)
from tab01 a, tab02 b
where a.dept = b.dept;

-- ex5)
select distinct(b.name)
from tab01 a
inner join tab02 b on a.dept = b.dept;

-- ex6)
select *
from tab02
where tab02.dept in (select dept from tab01);

-- ex7) ������û�� �� �а��� ����ϼ���.
select *
from tab02 d
where exists (select *
    from tab01 s
    where d.dept = s.dept);
*/
------------------------------------------------------------
/*
DROP TABLE menu;
CREATE TABLE menu(
    foodnum                number,    
    name                    varchar2(20)
);
DROP TABLE sell;
CREATE TABLE sell(
    no                number,
     count                           number,
      foodnum                          number
);

insert into menu values (1, '¥��');
insert into menu values (2, '�쵿');
insert into menu values (3, '�ø�');
insert into menu values (4, '����');
insert into menu values (5, '����');

insert into sell values (1, 2, 1);
insert into sell values (2, 3, 2);
insert into sell values (3, 4, 2);
insert into sell values (4, 2, 2);
insert into sell values (5, 1, 1);
-- �Ǹŵ� ������ ������ ����ϼ���.
-- ex1)
select s.foodnum from sell s;
--��� : (1, 2, 2, 2, 1)

select *
from menu d
--where d.foodnum = 1 or d.foodnum = 2;
--where d.foodnum in(1,2);
--where d.foodnum in (1, 2, 2, 2,1)
where d.foodnum in (select s.foodnum from sell s);

-- ex2) ���������� ������ �� ����.(�������� ����)- �Ǹŵ� ���
select *
from menu d
where exists(select s.foodnum  
        from sell s
        where d.foodnum = s.foodnum);
-- ex3) (�������� �����ϸ�) ��Ƽ ���� - �Ǹŵ��� ���� �ǸŸ��
select *
from menu d
where not exists(select s.foodnum  
        from sell s
        where d.foodnum = s.foodnum);
*/
        
-- ��������
-- ������ �������� : ���������� �������� 1���϶�
-- ������ �������� : ���������� ���� ����� n�� �϶�
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name                    varchar2(20),
    sal                         number
);

insert into tab01 values ('ȫ�浿', 200);
insert into tab01 values ('�̼���', 300);
insert into tab01 values ('���߱�', 400);
insert into tab01 values ('������', 100);

-- ȫ�浿���� �޿��� ���� ������?
--ex1) ȫ�浿�� �޿��� ���ΰ�?
select sal �޿� from tab01
where name = 'ȫ�浿';

--ex2) �޿��� 200���� ���� ������?
select * from tab01
where sal > 200;

-- ex3) ������ ���������� �񱳿����ڸ� ��� �����ϴ�.
-- ���������� ����� 2�� �̻� ������ ������ ��� �� �����ڸ� ����� �� ����.
-- ȫ�浿�� 2���ִٸ� ���� ���ϴ� �ڵ�. <- ������ �����ȣ������ �����ؼ� �ٲ� �� �ڵ� ����ؾ��Ѵ�.
select * --��������
from tab01
where sal > (
    select sal �޿� --���� ���� ����
    from tab01
    where name = 'ȫ�浿');
    
-- �������� ��� �޿����� ���� �޿��� �޴� ������ ����ϼ���.
--�������� ��� �޿��� �ñ��ϴ�. ��������
-- ��ձ޿��� 100���϶� 100������ ���� �޴� �����? �� ����
select name
from tab01
where sal > ( 
        select avg(sal) 
        from tab01
);
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name                    varchar2(20),
    city                       varchar2(20),
    job                         varchar2(20)
);

insert into tab01 values ('ȣ����1', '����', '����');
insert into tab01 values ('ȣ����2', '����', '����');
insert into tab01 values ('ȣ����3', '�뱸', '����');
insert into tab01 values ('ȣ����4', '�λ�', '����');
insert into tab01 values ('ȣ����5', '����', '����');
insert into tab01 values ('ȣ����6', '����', '����');
insert into tab01 values ('ȣ����7', '�뱸', '��ȹ');
insert into tab01 values ('ȣ����8', '�λ�', '����');
-- ȣ���� 6���� �ٹ� ���ð� �ٸ� ���� �߿� ������ ������ �ϴ� ����� ?
-- ȣ���� 6���� �ٸ����ÿ� �ٹ��ϸ鼭 ������ ������ �ϴ� ������?
--1.ȣ���� 6���� �ٹ��ϴ� ����
-- 2. ������ �ϴ� �����?
select city from tab01 where name = 'ȣ����6';
select job from tab01 where name = 'ȣ����6';

select * from tab01
where
    city != ( select city from tab01 where name = 'ȣ����6')
    and
    job = (select job from tab01 where name = 'ȣ����6');
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name                       varchar2(20),
     cityCode                         varchar2(20)
);

DROP TABLE tab02;
CREATE TABLE tab02(
    cityCode                       number,
     city                         varchar2(20)
);

insert into tab01 values ('ȣ����1', 1);
insert into tab01 values ('ȣ����2', 4);
insert into tab01 values ('ȣ����3', 3);
insert into tab01 values ('ȣ����4', 4);

insert into tab02 values (1, '����');
insert into tab02 values (2, '����');
insert into tab02 values (3, '�뱸');
insert into tab02 values (4, '�λ�');
-- �λ꿡 �ٹ��ϴ� ������ ? (��, ������� ������� �ʴ´�.
SELECT name ���� FROM tab01 
WHERE cityCode = (SELECT cityCode FROM tab02 WHERE city = '�λ�');
*/
--
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    empno                   number,
    ename                   varchar2(20),
    deptno                  number,
    sal                         number
);
DROP TABLE tab02;
CREATE TABLE tab02(
    deptno      number,
    dname      varchar2(20),
    loc            varchar2(20)
);

insert into tab01 values (1, 'ȫ�浿1', 10, 300);
insert into tab01 values (2, 'ȫ�浿2', 20, 400);
insert into tab01 values (3, 'ȫ�浿3', 20, 500);
insert into tab01 values (4, 'ȫ�浿4', 10, 600);

insert into tab02 values (10, '����', '����');
insert into tab02 values (20, '�繫 ', '����');
insert into tab02 values (30, '����', '�뱸');

--  1) ��ձ޿����� ���� ������?
select ename ���� 
from tab01 
where sal < (
    select avg( sal ) 
    from tab01
);

-- 2) ��� �޿����� ���� 20�� �μ��� ������?
select ename ���� 
from tab01 
where 
    sal < (select avg( sal ) from tab01) 
    and 
    tab01.deptno = 20;
    
-- 3) ��ü ����� ��� �޿����� ���� 20�� �μ��� ����� �� ���� �˻�
select * from tab01 a, tab02 b
where a.deptno = b.deptno
        and a.deptno = 20
        and a.sal < (select avg( sal ) from tab01);

-- select in ( select), any, all,exists ( ������ ��������...)
-- �߱��� ����� ������ �޿����� �޿��� ���� ���� �˻�
-- in(��� 10�� �߿� �߱��� ����� ������ 3��)
-- ������ �������� �����ڿ� ������ �����ڷκ��� ���� �޴� ������?
-- ������ ���� 
-- ȫ�浿1 - �̼���1
-- ȫ�浿2 - �̼���1
-- ȫ�浿3 - �̼���2
-- ȫ�浿4 - �̼���2
-- ����� 
-- �̼���1
-- �̼���2
-- �����ϴ� ������
-- + ���ߺο��� ������

-- ���ð� ����� ������  ���̿� ������ ������ ���� �˻�
DROP TABLE tab01;
CREATE TABLE tab01(
    ename varchar2(20),
    hobby varchar2(20),
    age number
);

insert into tab01 values ( 'ȫ�浿1', '����', 30);
insert into tab01 values ( 'ȫ�浿2', '���', 40);
insert into tab01 values ( 'ȫ�浿3', '����', 50);
insert into tab01 values ( 'ȫ�浿4', '���', 30);
insert into tab01 values ( 'ȫ�浿5', '����', 40);
insert into tab01 values ( 'ȫ�浿6', '���', 50);
insert into tab01 values ( 'ȫ�浿7', '����', 30);
insert into tab01 values ( 'ȫ�浿8', '���', 40);
insert into tab01 values ( 'ȫ�浿9', '����', 50);

select ename from tab01 where age in (select age from tab01 where hobby = '����');
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    sal number
);

insert into tab01 values ( 10);
insert into tab01 values ( 20);
insert into tab01 values ( 30);
insert into tab01 values ( 40);
insert into tab01 values ( 50);

select * from tab01;
-- �������� = �ζ��κ�
select * from (select  * from tab01 where sal > 20);

-- t1, t2�� with�� ; ������ ��ȿ����
with
t1 as (select  * from tab01 where sal >= 20),
t2 as (select  * from tab01 where sal <= 20)
select *from t1, t2;


-- ������ �� �� �ִ�.
select sal, sum(sal) over(order by sal) from tab01;
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name varchar2(20),
    sal number
);

insert into tab01 values ( 'ȫ�浿', 200);
insert into tab01 values ( '�̼���', 300);
insert into tab01 values ( '���߱�', 400);
insert into tab01 values ( '������', 100);

select * from tab01
where sal > (
    select sal
    from tab01
    where name = 'ȫ�浿'
);

--select * from user_views;
drop view view01;

create view view01 as  (
    select sal
    from tab01
    where name = 'ȫ�浿'
);
--select * from user_views;
select * from view01;
--�� �� ������ �ȵǴ� �ڵ�
--select * from tab01 where sal > view01;
select * from tab01 where sal > (select * from view01);

-- ��� �Ͱ� �ٸ����� ���� �ʵ�� ���� �ʹٸ�?
--select rownum, * from tab01; (�ȵȴ�)
select rownum, t1.*, sal, sal * 1.2 from tab01 t1
where rownum <= 2
order by name;
*/
/* 
id      name        salary
1       ȣ����10   30
2       ȣ����20   45
3       ȣ����30   29
*/
/*
drop table tab01;
create table tab01 (
    id number,
    name varchar2(20),
    salary number
);

drop sequence seq;
create sequence seq
increment by 1
start with 1;

insert into tab01 values(
    seq.nextval,
    'ȣ����' || to_char(seq.currval * 10),
    ceil(DBMS_RANDOM.value(10, 100)) );
insert into tab01 values(
    seq.nextval,
    'ȣ����' || to_char(seq.currval * 10),
    ceil(DBMS_RANDOM.value(10, 100)) );
select * from tab01;
*/
/*
drop table  tab01;
create table tab01(
    eid number,
    eno number,
    ename varchar2(20)
);
insert into tab01 values( 1,  10, 'ȫ�浿1');
insert into tab01 values( 2,  10, 'ȫ�浿1'); -- 
insert into tab01 values( 3,  20, 'ȫ�浿2');
insert into tab01 values( 4,  20, 'ȫ�浿2'); --
insert into tab01 values( 5,  20, 'ȫ�浿2'); --
insert into tab01 values( 6,  30, 'ȫ�浿3');
insert into tab01 values( 7,  30, 'ȫ�浿3'); -- 
insert into tab01 values( 8,  40, 'ȫ�浿4');
insert into tab01 values( 9,  50, 'ȫ�浿5');
insert into tab01 values(10,  50, 'ȫ�浿5'); --

select * from tab01
where eid in (select min(eid) from tab01 group by eno);

select * from tab01
where not eid in (select min(eid) from tab01 group by eno);

-- group by ������� ���� ��
select * from tab01 a
where eid > (select min(eid) from tab01 b
                        where a.eno = b.eno -- �ٽ� ����(���̺��� 2���� �����߱� ������ ������ ���)
                        );
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    ROW1 VARCHAR2(20),
    ROW2 VARCHAR2(20),
    PRICE NUMBER
);
insert into tab01 values( 'HP', 'T1', 10);
insert into tab01 values( 'HP', 'T1', 20);
insert into tab01 values( 'HP', 'T2', 30);
insert into tab01 values( 'HP', 'T2', 40);
insert into tab01 values( 'LD', 'T3', 50);
insert into tab01 values( 'LD', 'T3', 60);
insert into tab01 values( 'LD', 'T4', 70);
insert into tab01 values( 'LD', 'T4', 80);
insert into tab01 values( 'PP', 'T1', 70);
insert into tab01 values( 'PP', 'T1', 80);

--group by
--decode
--sum
--t3       110  -- ��
--hp      100 -- ��
--pp      150 -- ��
--t4       150 -- ��
select decode(row1,
        'HP', 
        row1,
        'LD',
        row2,
        'PP'
        ),
        SUM(PRICE)
from tab01
group by decode(row1,
        'HP', 
        row1,
        'LD',
        row2,
        'PP'
);
*/

DROP TABLE tab01;
CREATE TABLE tab01(
    saledate date,
    chulqty NUMBER
);
/*
insert into tab01 values( '20200604',  10);
insert into tab01 values( '2020-06-04',  20);
insert into tab01 values( '2020/06/04',  30);
insert into tab01 values( '20210210',  40);
insert into tab01 values( '20210210',  50);
insert into tab01 values( sysdate,  60);
--ex1) ��¥ ������ ���
select * from tab01;
--ex2)
select TO_CHAR(saledate, 'YYYYMMDD') from tab01;

select sum(chulqty) from tab01;
-- ex3) 6�� 5�� ���� �� �Ǹŷ� ���
select sum(decode(saledate, 
                        '20/06/04', chulqty,
                        0)
)
from tab01;
-- ex4) �׻� ���� �Ǹŷ�...
select sum(decode(
        TO_CHAR(saledate, 'YYYYMMDD'),
         TO_CHAR(sysdate, 'YYYYMMDD'), chulqty,0)
         )
from tab01;
*/
/*
insert into tab01 values( '20210201', 1 );
insert into tab01 values( '20210202', 2 );
insert into tab01 values( '20210203', 3 );
insert into tab01 values( '20210204', 4 );
insert into tab01 values( '20210205', 5 );
insert into tab01 values( '20210206', 6 );
insert into tab01 values( '20210207', 7 );
insert into tab01 values( '20210208', 8 );
insert into tab01 values( '20210209', 9 );
insert into tab01 values( '20210210', 1 );

select sign(-5), sign(0), sign(5) from dual;
select sum(decode(saledate, 
                        '21/02/07', chulqty,
                        0)
)
from tab01;
select sum(decode(TO_CHAR(saledate,'YYYYMMDD'),
                    '20210207',chulqty,
                        0)
)
from tab01;

-- ������ �������� ���� �հ�
-- ��������
select ( '20210210' - TO_CHAR(SALEDATE, 'YYYYMMDD' ) ) A,
    7-( '20210210'-TO_CHAR(SALEDATE, 'YYYYMMDD' ) ) B,
    sign( 7 - ( '202010210'-TO_CHAR(SALEDATE, 'YYYYMMDD'))) C
from tab01;

select sum( decode
                        ( sign
                                ( 7 -('20210210' - TO_CHAR ( SALEDATE, 'YYYYMMDD'))), -- ������ �հ�
                        1,
                        CHULQTY,
                        0)
)
FROM TAB01;
*/
/*
insert into tab01 values( '20180101', 1 );
insert into tab01 values( '20180201', 2 );
insert into tab01 values( '20180301', 3 ); -- 6
insert into tab01 values( '20190101', 2 );
insert into tab01 values( '20190201', 3 );
insert into tab01 values( '20190301', 4 ); -- 9
insert into tab01 values( '20200101', 3 );
insert into tab01 values( '20200201', 4 );
insert into tab01 values( '20200301', 5 ); -- 12
-- �⵵�� �ǸŰ���
select substr(saledate, 1, 2) as year , sum(chulqty)
from tab01
group by substr(saledate, 1, 2)
order by year;
*/
drop table tab01;
create table tab01(
    ��ǰ��ȣ number,
    ��ǰ�̸� varchar2(20),
    ��ǰ�ܰ� number
);
drop table tab02;
create table tab02(
    ��ǰ��ȣ number,
    �Ǹż��� number
);
insert into tab01 values (1, '�ٳ���', 1000);
insert into tab01 values (2, '������', 2000);
select * from tab01;

insert into tab02 values (1, 1); -- �ٳ��� 1�� �Ǹ�
insert into tab02 values (1, 2); -- �ٳ��� 2�� �Ǹ�
insert into tab02 values (1, 3); -- �ٳ��� 1�� �Ǹ�
insert into tab02 values (2, 2); -- ������ 2�� �Ǹ�
select * from tab02;

-- �ٳ����� �� �ǸŰ����� �� �Ǹ� �ݾ��� ����ϼ���.
select sum(�Ǹż���), sum(�Ǹż��� * ��ǰ�ܰ�)
from tab01 a, tab02 b
where a.��ǰ��ȣ = b."��ǰ��ȣ"
and a."��ǰ�̸�" = '�ٳ���';

select a.��ǰ�̸�, sum(�Ǹż���), sum(�Ǹż��� * ��ǰ�ܰ�)
from tab01 a, tab02 b
where a.��ǰ��ȣ  =  b.��ǰ��ȣ
group by a.��ǰ�̸�
having a.��ǰ�̸� = '�ٳ���';

COMMIT;