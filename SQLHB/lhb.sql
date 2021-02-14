-- �ּ� ����

/*
-- sql �����̴�.
-- *(�ƽ�Ʈ��) : ���ϵ�ī��( ��� ) * ?
-- �����Ű�� ����� 2����
    -- F5
    --ctrl + enter : ������� ���̺� �������� �����ش�.

-- C���� ' '�� ���ڸ� �ǹ��ϰ� " "�� ���ڿ��� �ǹ��Ѵ�.
-- ����Ŭ������ ' ' ������ ���ڿ� . ���ڿ� ǥ�ô� ' '�̴�.
-- SET PAGESIZE 14; // 14 - 4 = 10 <- 10�پ� ���� �о��
-- ���ڿ��� �ٷ�� Ÿ���� VARCHAR2 : ����2
-- ID , Name, Alias, Password, Sex, Address, city, PostCode
-- Country, Birthday, Photo(���ϸ�), Salary, Phone 
-- �������� ��ҹ��� ������ ���� ������, �빮�ڰ� �����̴�.

-- ���̺��� �����.( SQL Developer���� ���̺��� ���� ���� �� ������, �� �ǹ� ����.)
-- �ݵ�� �������� �����ݷ����� ������ �Ѵ�.
*/
/*
--��� ���̺� ����� �����ּ���
--SELECT * FROM TAB;

--�������� ��� �ּ���
PURGE RECYCLEBIN;

DROP TABLE tab01;
--���̺� �������ּ���.
CREATE TABLE tab01(
    age NUMBER              -- �÷��� Ÿ��,  
);
--���� �߿����� �ʴ�.(���̺� �̸��� ������ �� �ִ�.)
rename tab01 to tab02; -- old name to new name

-- �������� �����ּ���.
SHOW RECYCLEBIN;

--���̺� ���ô�
SELECT * FROM TAB;

-- ���������� ����Ǵ°�
COMMIT; 
*/
/*
PURGE RECYCLEBIN;
DROP TABLE tab01;
-- ���̺� �÷��� CRUD �� �� �ִ�.
CREATE TABLE tab01(
    ID          VARCHAR2 (20), -- ������...�ּ����� �ۼ��ϴ� ���� ����
    NAME    VARCHAR2 (20),
    age        NUMBER              -- �÷��� Ÿ��,  
);


--DESC tab01;
--Create
INSERT INTO tab01(id, name, age) VALUES( 1, 'ȣ����1', 1000);
INSERT INTO tab01(id, name, age) VALUES( 2, 'ȣ����2', 2000);
INSERT INTO tab01(id, name, age) VALUES( 3, 'ȣ����3', 3000);

-- Update
-- if ��ſ� where�� ���ǰ�
-- �񱳿����� == ��ſ� (=)�� ���ȴ�.
UPDATE tab01 SET age = 4000,  name = '������' WHERE id = 3;

--Delete
DELETE FROM tab01 WHERE id = 2;

--Read
--���̺�� �ִ� ������ �����ּ���.
SELECT * FROM tab01;

COMMIT; 
*/

/* -----------------------------------------------------------
PURGE RECYCLEBIN;
DROP TABLE emp1;
-- ���̺� �÷��� CRUD �� �� �ִ�.
CREATE TABLE emp1(
    eno            NUMBER (4), -- �����ȣ(employee)
    ename       VARCHAR2 (20),
    sal             NUMBER             -- �޿�
);
--ex1) ����� ���
--INSERT INTO emp1 (eno, ename, sal) VALUES ( 1009, '������', 500);

--ex2) ������ ���
--�÷�������ŭ ��� �Է��ؾ� �Ѵ�.
INSERT INTO emp1 VALUES ( 1001, '�ڳ���', 350);

--ex3) �����ڵ�
--INSERT INTO emp1 VALUES ( '�ڳ���1', 350);

--ex4) �ʿ��� �ʵ常 �Է��� �����ϴ�
INSERT INTO emp1 (ename, sal) VALUES ( 'ȣ����', 500);

--ex5) ������� ����� �� �ִ�.
INSERT INTO emp1 VALUES (1000+4, '���1', 350 * 1.2);

--ex6) NULL���� �Է��� �� �ִ�.
INSERT INTO emp1 VALUES (NULL, '���2', 350 * 1.2);

--ex7) ��������δ� ��� ���Ѵ�.
-- ���ڿ� �Է��Ҷ��� ' ' ���̿��� ���ڿ��� �Է��ؾ��Ѵ�.
--sqlplus���� �ϸ� �ȵȴ�.(���Թ��� �ƴ�)
--INSERT INTO emp1 VALUES (&a, &b, &c);
--INSERT INTO emp1 VALUES (&a, '&b', &c);
--------------------------------------------------------------------------------
--ex1) ���̺� ��� ������ ����.
--SELECT * FROM tab;

--ex2) ���̺� ���� ������ ����.
SELECT * FROM emp1;

--ex3) row�� ������ �˰� ���� ��
SELECT count(*) from emp1;

--ex4) null���� ������ �÷����� row�� ����
SELECT count(eno) from emp1;

--ex5) ���������� �ʿ��� �ʵ常 ��´�.
SELECT eno,sal FROM emp1;

--ex6) �÷��� �̸� ����(��Ī) >> ���� ���ȴ�.
SELECT eno AS ���,ename AS �̸�, sal AS �޿� FROM emp1;
--������ �������� �ڵ�
SELECT eno ���,ename �̸�, sal �޿� FROM emp1;

--ex7) ��Ī ���̿� ������ �������� " " �� ����Ѵ�.
SELECT eno AS "��  ��",ename AS �̸�, sal AS �޿� FROM emp1;

--ex8) ���ڿ� ����( �÷� ���� )
--|| �� ������ �����̶�� �Ѵ�.
SELECT ( eno || ename ) , sal FROM emp1;

--ex9) ��Ī�� �����ϰ� �Ǹ�
SELECT ( eno || ename ) AS ����̸�, sal AS �޿� FROM emp1;

--ex10) �����ؼ� ������ �����ϴ�. 
SELECT eno, eno, ( eno || ename ) AS ����̸�, sal AS �޿� FROM emp1;

--ex11) Distinct �ߺ����� �ʰ� ���� ���
INSERT INTO emp1 VALUES (1111, '������', 1350);
INSERT INTO emp1 VALUES (1221, 'ȣ����', 2350);
SELECT * FROM emp1;
SELECT DISTINCT(ename) FROM emp1;

--ex12) Distinct �� ����� ������ ��´�.
-- ����� 1���� ���´�.
SELECT count (DISTINCT(ename)) FROM emp1;

--ex13) ����� 1�� ������ �Ͱ� N�� ������ select�� ��� �� ���� ����.
-- row ������ �ٸ��� ��Ÿ���� ������ ����� �� ����.
--SELECT eno, count (DISTINCT(ename)) FROM emp1;

--ex14) �ʵ忡�� ������ ����� �� �ִ�.
-- NULL �����ʹ� ����Ŀ��� ���õȴ�.
SELECT sal AS �޿�, sal*1.2 AS �Ǽ��ɾ�, sal*1.2 - sal AS ���ʽ� FROM emp1;
SELECT eno, sal AS ����, sal*12 AS ���� FROM emp1;

--ex14) ���̺� ������� �ʰ� dual ���̺��� ����� �� �ִ�.
--�׽�Ʈ �뵵�� ���� ���ȴ�.(�ӽ����̺�)
-- ��� ����
--mod ������ , floor ��
select 8+3, 8-3, 8*3, 11/3, floor(11/ 3), mod(11, 3), floor(-1.5)  from dual;

COMMIT; 
-------------------------------------------------------------------------------------------------*/
/*
PURGE RECYCLEBIN;
DROP TABLE emp1;
-- ���̺� �÷��� CRUD �� �� �ִ�.
CREATE TABLE emp1(
    eno            NUMBER (4), -- �����ȣ(employee)
    ename       VARCHAR2 (20),
    sal             NUMBER             -- �޿�
);

INSERT INTO emp1 VALUES ( 1009, '������', 500);
INSERT INTO emp1 VALUES ( 1001, 'ȣ����', 200);
INSERT INTO emp1 VALUES ( 1002, 'ȣ����', 200);
INSERT INTO emp1 VALUES ( 1003, '���', 150);
INSERT INTO emp1 VALUES ( 1004, '���̾�', 150);
INSERT INTO emp1 VALUES ( 1005, 'ȣ����', 350);
--ex16) ����( �������� ����ϱⰡ ���� �����ϴ�. )
-- ���� ����� �߻��Ѵ�.
-- 100������ ����Ÿ�� �����ؼ� 10���� �ּ���.
SELECT * FROM emp1;
SELECT * FROM emp1 order by sal asc; -- ascanding
SELECT * FROM emp1 order by sal desc; -- descanding
--���� ���� ���������...(eno : 1, ename : 2, sal : 3)
SELECT * FROM emp1 order by 3; 
SELECT * FROM emp1 order by sal asc, eno desc;
SELECT * FROM emp1 order by sal, eno desc;
SELECT * FROM emp1 order by sal, eno;
*/
/*
PURGE RECYCLEBIN;
DROP TABLE emp1;
-- ���̺� �÷��� CRUD �� �� �ִ�.
CREATE TABLE emp1(
    ename       VARCHAR2 (20),
    kor             NUMBER,
    eng             NUMBER,
    mat             NUMBER
);

INSERT INTO emp1 VALUES (  '������', 50, 33, 52);
INSERT INTO emp1 VALUES (  'ȣ����1', 60,44, 23);
INSERT INTO emp1 VALUES (  'ȣ����2', 80, 55,98);
INSERT INTO emp1 VALUES ( '���', 15,66,54);
INSERT INTO emp1 VALUES ( '���̾�', 15,11,88);
INSERT INTO emp1 VALUES ( 'ȣ����3', 35,3,99);
--ex17) ���� �տ� ���� ����
SELECT * FROM emp1;
-- ��� 1
SELECT ename, kor, eng, mat, (kor + eng + mat) 
FROM emp1 
ORDER BY (kor + eng + mat);
-- ��� 2
SELECT ename, kor, eng, mat, (kor + eng + mat) AS sumsum 
FROM emp1 
ORDER BY (sumsum) desc;

-- ex18) �񱳿��� >, <, >=, <=, =(����), != ( <>, ^=)
SELECT * FROM emp1 where kor > 40;
SELECT ename FROM emp1 where kor > 40;

SELECT ename, (kor + eng + mat) �ջ����� 
FROM emp1 
where (kor+eng+mat) > 120 
ORDER BY ename;

--ex19) where�������� ��Ī�� ����� �� ����.
--SELECT kor AS aliaskor 
--FROM emp1 
--WHERE aliaskor > 50;

--ex20) where�������� ��Ī�� ����� �� ����.
--SELECT
--�÷�         -- ��Ī ���(O)
--FROM ���̺��
--WHERE       -- ��Ī ���(X)
--GROUP BY    -- ��Ī ���(O)
--HAVING      -- ��Ī ���(O)
--ORDER BY    -- ��Ī ���(O)
*/
/*
PURGE RECYCLEBIN;
DROP TABLE emp1;

CREATE TABLE emp1(
    ename       VARCHAR2 (20),
    kor             NUMBER,
    eng             NUMBER,
    mat             NUMBER
);

INSERT INTO emp1 VALUES (  '������', 50, 33, 52);
INSERT INTO emp1 VALUES (  'ȣ����1', 60,44, 23);
INSERT INTO emp1 VALUES (  'ȣ����2', 80, 55,98);
INSERT INTO emp1 VALUES ( '���', 15,66,54);
INSERT INTO emp1 VALUES ( '���̾�', 15,11,88);
INSERT INTO emp1 VALUES ( 'ȣ����3', 35,3,99);

--ex21)���̺�� ��ſ� �������� ����� �� �ִ�.
-- �ζ��� ��, ��������
SELECT COUNT(*) FROM emp1;
SELECT COUNT(*) FROM (SELECT * FROM emp1 WHERE kor > 50);
-- �� ����� ����
SELECT COUNT(*) FROM emp1 WHERE kor > 50;

--ex22) AND, OR, NOT ���
SELECT * FROM emp1
WHERE kor > 30 AND kor < 80;

SELECT * FROM emp1
WHERE kor > 30 OR ename = '���';

SELECT * FROM emp1
WHERE NOT(kor > 30 AND kor < 80);

--ex23)IN�� (= OR)�� ���� ����
SELECT * FROM emp1
WHERE kor = 50 OR kor = 15 OR kor = 40;

SELECT * FROM emp1
WHERE kor NOT IN(50, 15, 40);
--WHERE kor NOT IN(�������� �� �ִ�.);
--WHERE kor NOT IN(SELECT ���� ��� �� �� �ִ�.);
*/
/*
PURGE RECYCLEBIN;
DROP TABLE TAB01;

CREATE TABLE TAB01(
    ename       VARCHAR2 (20),
    mt          VARCHAR2 (20)
);

INSERT INTO TAB01 VALUES (  'ȣ����1', '���ѻ�');
INSERT INTO TAB01 VALUES (  'ȣ����2', '������');
INSERT INTO TAB01 VALUES (  'ȣ����3', '���ѻ�');
INSERT INTO TAB01 VALUES (  'ȣ����4', '���ǻ�');
INSERT INTO TAB01 VALUES (  'ȣ����5', '������');
SELECT ename From TAB01 WHERE mt = '������' OR mt = '������';
SELECT ename From TAB01 WHERE mt IN ('������' , '������');
-- ���� ���̰� ���� 10�� �ȿ� ���� ���� �ٳ�� ���� ����� ����ϼ���.
DROP TABLE TAB02;
CREATE TABLE TAB02(
    mt       VARCHAR2 (20),
    height          NUMBER,
    national        ����
);

INSERT INTO TAB02 VALUES ( '���ѻ�', 1000);
INSERT INTO TAB02 VALUES ( '������', 2000);
INSERT INTO TAB02 VALUES ( '���ǻ�', 1500);
INSERT INTO TAB02 VALUES ( '������', 1800);

-- ���� ���̰� 1600 �̻�
--select mt from tb02 where height > 1600;
-- ���� ���̰� 1600 ���� ���� ���� �ٳ�� ���� ����� ����ϼ���.
-- ����)���� ���̰� ���� 10�� �ȿ� ���� ���� �ٳ�� ���� ��ư�� �� ����ȣ�� ����ϼ���.
SELECT ename 
from TAB01 
WHERE mt in( 
    SELECT mt 
    FROM tab02
    WHERE height > 1600
);

--ex24) between
SELECT * FROM emp1
where kor >= 30 and kor <= 80;
SELECT * FROM emp1
where kor BETWEEN 30 AND 80
*/
/*
PURGE RECYCLEBIN;
DROP TABLE emp1;

CREATE TABLE emp1(
    ename       VARCHAR2 (20),
    kor             NUMBER,
    eng             NUMBER,
    mat             NUMBER
);

INSERT INTO emp1 VALUES (  '', 50, 33, 52);
INSERT INTO emp1 VALUES (  null, 60,44, 23);
INSERT INTO emp1 VALUES (  'ȣ����2', null, 55,98);
INSERT INTO emp1 VALUES ( '���', 15,null,54);
INSERT INTO emp1 VALUES ( '���̾�', null,11,88);
INSERT INTO emp1 VALUES ( 'ȣ����3', 35,3,99);
--ex25)
SELECT * FROM emp1
WHERE ename like 'ȣ%';

--ex26) null
--not in
--not between
--not like
--is null >> ������ ���� null�ΰ�...
--is not null

--ex27) null�� �ʿ��� ���
-- ���� �����Ϳ��� ����Ÿ�� �ҽ� Ȥ�� ���� ���
-- ���� ���ε� ���� ������ ���� ���� ��
-- ��ȥ�� ���� ��ȥ �����
-- ��й�ȣ ã�⸦ �������� �ʾ�����
-- �̼������� ��Ŵ���

--ex28)�ϴ� ������ ����.
SELECT * FROM emp1
--WHERE kor = null; -- ���� �ؾ� �Ѵ�.(������� �ʴ� ���̽�)
--WHERE kor is null; --(����ϴ� ���̽�)
WHERE kor is not null; --(����ϴ� ���̽�)

--ex29)
SELECT * FROM emp1
WHERE kor is null or eng is null;

--ex30) ���ڿ��� �ƹ��͵� �ȵ�('') ������ nulló�� �ȴ�.
SELECT * FROM emp1
WHERE ename is null;
*/
/*
PURGE RECYCLEBIN;
DROP TABLE emp1;
CREATE TABLE emp1(
    ename       VARCHAR2 (20),
    address     VARCHAR2 (20)
);

INSERT INTO emp1 VALUES (  '�ϱ浿', '����');
INSERT INTO emp1 VALUES (  '�̱浿', '����');
INSERT INTO emp1 VALUES (  '��浿', '����');
INSERT INTO emp1 VALUES (  '��浿', '����');
INSERT INTO emp1 VALUES (  '���浿', '����');
INSERT INTO emp1 VALUES (  '���浿', '�뱸');

-- ex31) ��浿�� ����� ������ ������ ���� ����� ����� ����ϼ���.
-- ���̺��� �г����� ����� �� �ִ�.
-- �ӽ����̺��� �����ϱ� ���Ͽ� ���������� ���Ǿ���.
SELECT s1.ename FROM emp1 s1, (SELECT address FROM emp1 where ename = '��浿') s2
WHERE s1.address = s2.address;

-- ex32)max, min
-- ( > all ), ( < any ) >> max�� ���� ���� ã�´ٴ� �ǹ�
-- ( < all ), ( > any ) >> min�� ���� ���� ã�´ٴ� �ǹ�
--WHERE SALARY > 200 OR SALARY > 300 OR SALARY > 400 (������� ������ �� ������...)
--SALARY�� ���������� ���� ��Ȳ�̶�� �̾߱�� �޶�����. ������ ANY�� ����ϴ� ���̴�.
-- 200, 300, 400 �߿��� �ּҰ����� ū���ΰ� ���°��̴�.
-- IN�ϰ� ���谡 �ִ� �� ������ IN�� =���� ���� �� ��(������ IN���� ����� ���� ����.)

--WHERE SALARY > ANY(200, 300, 400) >> �� ����� ���� ������ ����.
--WHERE SALARY > 200

--WHERE SALARY < ANY(200, 300, 400) 
--WHERE SALARY < 400

--WHERE SALARY > ALL(200, 300, 400)  
--WHERE SALARY < 200

--WHERE SALARY < ALL(200, 300, 400)  
--WHERE SALARY > 400
*/
/*
PURGE RECYCLEBIN;
DROP TABLE tab1;
CREATE TABLE tab1(
    dept         NUMBER, -- �μ���ȣ (��ȹ�μ�, ���ߺμ�, �����μ�, �Ѱ��μ�, ȫ���μ�)
    name       VARCHAR2 (20),
    sal        NUMBER
);
INSERT INTO tab1 VALUES (30,  'tiger0', 999);
INSERT INTO tab1 VALUES (10,  'tiger1', 100);
INSERT INTO tab1 VALUES (20,  'tiger2', 200);
INSERT INTO tab1 VALUES (30,  'tiger3', 300);
INSERT INTO tab1 VALUES (40,  'tiger4', 400);
INSERT INTO tab1 VALUES (10,  'tiger5', 500);
INSERT INTO tab1 VALUES (20,  'tiger6', 600);
INSERT INTO tab1 VALUES (30,  'tiger7', 700);
INSERT INTO tab1 VALUES (10,  'tiger8', 800);
INSERT INTO tab1 VALUES (20,  'tiger9', 350);

-- 20�� �μ��� �޿��� ���� ���� �޴� ������� �޿��� ���� �������� ��� ����ϼ���.
--����(1) 20�� �μ��� �޿��� �˻��Ѵ�.
SELECT sal FROM tab1 WHERE dept = 20; -- 200, 600, 350
--����(2)
SELECT * FROM tab1 WHERE sal < ANY(200, 600, 350);
--����(3)
SELECT *
FROM tab1
WHERE sal < ANY(
    SELECT sal
    FROM tab1
    WHERE dept = 20
);
-- �İ������� ���� ���� ������ ���� �л����� ���� �ٸ��а� �л����� ������ ?
--    �İ� 40
--    �İ� 20 --> �İ� �߿��� ���� ���� �л�
--    �İ� 50
--    �߱� 80
--    �߱� 70
--    �߱� 10 ->> ���
--    �Ͼ� 40
--    �Ͼ� 05 ->> ���
*/
------------------------------------------------
/*
--ex30)
purge RECYCLEBIN;
DROP TABLE tab01; 
CREATE TABLE tab01(             
    eno         number,
    ename        VARCHAR2(20),
    sal         NUMBER
);
INSERT INTO tab01 VALUES (10,'t2',100);
INSERT INTO tab01 VALUES (20,'tiger2',null);
INSERT INTO tab01 VALUES (30,'monkey3',200);
INSERT INTO tab01 VALUES (40,'tiGer4',300);
INSERT INTO tab01 VALUES (50,'����',300);
--ex31)
--����� �빮�ڷ� ��ȯ���� ���������Ͱ� �빮�ڰ� �ȰŴ� �ƴϴ�.
select upper(ename) from tab01;
select lower(ename) from tab01;
select initcap(ename) from tab01;
select * from tab01 where upper(ename) = upper('TIGER2');
select * from tab01 where lower(ename) like 'tiger%';
--ex31) ������ΰ�
select length(ename), lengthb(ename) from tab01;
select * from tab01 where length(ename) > 3;
--�̸��� ������ ��츦 ã�ƶ�
select * from tab01 where length(ename) <=2;
--�̸��� 3�ڸ��� �ƴ� ��츦 ã�ƶ�
select * from tab01 where length(ename) !=3;
--ex32)
DROP TABLE tab02; 
CREATE TABLE tab02(             
    eno         number,
    call        varchar2(20)
);
INSERT INTO tab02 VALUES (10,'100-200-300');
INSERT INTO tab02 VALUES (20,'400)500-600');
INSERT INTO tab02 VALUES (30,'700-800-900');
INSERT INTO tab02 VALUES (40,'700-800-900');
INSERT INTO tab02 VALUES (50,'700)800-900');
INSERT INTO tab02 VALUES (60,'02)800-900');
--substr : Ư���κ��� ���ڿ��� �и��Ҷ�
--ù��° �ε����� 1�̴�
select substr(tel, 5, 3) , substr(tel,5) from tab02;
DROP TABLE tab03; 
CREATE TABLE tab03(             
    eno         number,
    tel        varchar2(20)
);
INSERT INTO tab03 VALUES (10,'ȣ���̸���1��.');
INSERT INTO tab03 VALUES (20,'ȣ���̳�������2��..');
INSERT INTO tab03 VALUES (30,'������ȣ���̸���3��...');
INSERT INTO tab03 VALUES (40,'12345678ȣ����...');
INSERT INTO tab03 VALUES (50,'����������3��...');
--��ȭ������ �������ϼ��� �� ������ �涧�� �� 4�ڸ��� ���
select substr(tel,1,4), length(tel) from tab03;
select substr(tel,length(tel)-4) from tab03;
-- instr
--select instr(tel, 'ȣ����') from tab03;
select substr(call, 1, instr(call,')')) from tab02;
*/
-------------------------------------------------------
/*
purge RECYCLEBIN;
DROP TABLE tab01; 
CREATE TABLE tab01(             
    eno         number,
    ename        varchar2(20)
);

INSERT INTO tab01 VALUES (10,'ȣ����-����');
INSERT INTO tab01 VALUES (20,'��ȣ���̸�-��');
INSERT INTO tab01 VALUES (30,'����ȣ����');
INSERT INTO tab01 VALUES (30,'����_ȣ����');

SELECT REPLACE(ename, 'ȣ����', '�ڳ���') from tab01;
SELECT REPLACE(ename, '-', ' ') from tab01;
SELECT REPLACE(ename, '-', '') from tab01;

INSERT INTO tab01 VALUES (10,'tiger1');
INSERT INTO tab01 VALUES (20,'tiger2');
INSERT INTO tab01 VALUES (30,'tiger3');
INSERT INTO tab01 VALUES (30,'tiger4');
-- rpad, lpad(right, left)
-- ���� ������ ���� * ä��
select rpad(ename, 10, '*') from tab01;
select lpad(ename, 10, '*') from tab01;
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01; 
CREATE TABLE tab01(             
    eno         number,
    ename        varchar2(20)
);
INSERT INTO tab01 VALUES (10,'800123-1234561');
INSERT INTO tab01 VALUES (20,'900456-9999322');

--800123-*******
--900456-*******
select rpad(substr(ename, 1, instr(ename, '-')), 14, '*') from tab01;
*/
/*------------------------------------------------------------------------------------
purge RECYCLEBIN;
DROP TABLE tab01; 
CREATE TABLE tab01(             
    eno         number,
    ename        varchar2(20)
);
--concat
INSERT INTO tab01 VALUES (10,'ȣ����');
INSERT INTO tab01 VALUES (20,'�ڳ���');
INSERT INTO tab01 VALUES (30,'������');

SELECT CONCAT(ename, ':') from tab01;
SELECT CONCAT(eno, ename) from tab01;
SELECT CONCAT(eno, CONCAT(':',ename)) from tab01;
SELECT eno || (':' || ename) ���� from tab01;
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01; 
CREATE TABLE tab01(             
    eno         number,
    ename        varchar2(20)
);
--trim(�������� ltrim, rtrim )
INSERT INTO tab01 VALUES (10,' ȣ���� ');
INSERT INTO tab01 VALUES (20,'�� �� ��');
INSERT INTO tab01 VALUES (30,'_������_');
INSERT INTO tab01 VALUES (30,'��_��_��');
-- ���� ���� �ִ� �����̽��� �����Ѵ�.
select trim(ename) from tab01;
-- ���� ���� �ִ� _ ����
SELECT TRIM('_' FROM ename) from tab01;
-- id�� �Է��ϴµ�
-- tiger
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01; 
CREATE TABLE tab01(             
    eno         number,
    ename        varchar2(20)
);

-- ~.4 ���� .5~ �ø�
select round(1234.4),round(1234.5) from dual;
-- �Ҽ��� 2��°���� ��������
select round(1234.5678, 2) from dual;
-- 2��° �ڸ����ڱ��� �÷�����
select round(1234, -2) from dual;
-- 1��° �ڸ����ڱ��� �ø��ų� ��������
select round(1234, -1), round(1235, -1) from dual;

--trunc(�ݿø� ���� ������ �߶����)
select trunc(1234.4), trunc(1234.5) from dual;
--trunc(�ݿø� ���� ù��° ���ڱ��� �߶����)
select trunc(1234, -1), trunc(1235, -1) from dual;

--trunc
select ceil(3.14), floor(3.14), ceil(-3.14), floor(-3.14) from dual;
select floor(7/3), mod(7,3) from dual;

select 10+20 from dual;
-- �Ϲ����� ���α׷������� ���� + �����̸� ���ڰ� �ȴ�.
-- ����Ŭ�����ͺ��̽������� ���ʹ� �ٸ��� ���ڰ� �ȴ�.
select '10' + '20' from dual;
-- ���� : ������ �ȵȴ�(���� ��Ű�� ���ؼ� ������ ������ �Ѵ�.)
--select 'tiger' + 'win' from dual;
select 'tiger' || 'win' from dual;
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01;
CREATE TABLE tab01(
    eno         number,
    ename        varchar2(20)
);

INSERT INTO tab01 values(null, 'ȣ����');
INSERT INTO tab01 values(30, NULL);

SELECT 100 + eno, ename from tab01;
--nvl�� ����ϸ� null�� ���꿡 ������ �� �ִ�.(���� �ִٸ� 0 Ȥ�� '�͸����� ǥ��')
SELECT 100 + nvl(eno, 0), nvl(ename, '�͸�') ename from tab01;
-- ���̸� 20�� ���õǰ� ���� �ƴϸ� 10�� ���õ� ��Ȳ(���ڿ��� ������ ����)
SELECT 100 + nvl2(eno, 10, 20), nvl2(ename, ename, '�͸�') ename from tab01;
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01;
CREATE TABLE tab01(
    eno         number,
    ename        varchar2(40)
);
DROP TABLE tab02;
CREATE TABLE tab02(
    eno         number,
    ename        varchar2(40)
);
INSERT INTO tab01 values(10, 'tiger1');
INSERT INTO tab01 values(30, 'tiger2');
INSERT INTO tab01 values(10, 'tiger3');

INSERT INTO tab02 values(20, 'tiger3');
INSERT INTO tab02 values(30, 'tiger4');
INSERT INTO tab02 values(40, 'tiger5');

--������ �ʵ�� Ÿ���� ��ġ�ؾ� ����� �� �ִ�.
select  ename from tab01
union -- ������( �ߺ��� ����Ÿ�� 1���� ����� ���ŵȴ�.)
select  ename from tab02;

select  ename from tab01
union all -- ������( �ߺ��� ����Ÿ�� 1���� ����� ���ŵȴ�.)
select  ename from tab02;

--�����յ�����
select  ename from tab01
intersect -- ������( �ߺ��� ����Ÿ�� 1���� ����� ���ŵȴ�.)
select  ename from tab02;

--�����յ�����
select  ename from tab01
intersect -- ������( �ߺ��� ����Ÿ�� 1���� ����� ���ŵȴ�.)
select  ename from tab02;

select  ename from tab01
minus -- ������
select  ename from tab02;
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01;
CREATE TABLE tab01(
    eno         number,
    ename        varchar2(40),
    salary NUMBER
);
DROP TABLE tab02;
CREATE TABLE tab02(
    eno         number,
    ename        varchar2(40)
);
INSERT INTO tab01 values(10, 'tiger1', 100);
INSERT INTO tab01 values(30, 'tiger2', 200);
INSERT INTO tab01 values(10, 'tiger3', 300);

INSERT INTO tab02 values(20, 'tiger3');
INSERT INTO tab02 values(30, 'tiger4');
INSERT INTO tab02 values(40, 'tiger5');

--���� ���͸� ������ Ȱ���Ͽ� union ����Ѵ�.)
--��ġ���� �ʴ� ��쿡 null�� ��ü�� �� �ִ�.
--union�� �ѹ� �̻� ����� �� �ִ�.

--ex) �������� �̸� + �Һ����� �̸�
select  ename from tab01 where eno <= 20
union
select  ename  from tab02 where eno >= 30;
*/
--purge RECYCLEBIN;

--decode(�������� ���� ���´�.)
-- switch���� �����ϴ� goto���� ����ϴ�.
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    eno         number
);

INSERT INTO tab01 values(10);
INSERT INTO tab01 values(30);
INSERT INTO tab01 values(10);
select * from tab01;
select decode(eno,
    10, 'ȣ����1',
    20, 'ȣ����2', 
    30 , 'ȣ����3') from tab01;
*/
/*
switch (eno){
    case 10:
        'ȣ����1',
    break;
}
*/

/*
purge RECYCLEBIN;

--decode(�������� ���� ���´�.)
-- switch���� �����ϴ� goto���� ����ϴ�.

DROP TABLE tab01;
CREATE TABLE tab01(
    eno         number,
    sal         NUMBER
);

INSERT INTO tab01 values(10,    1000);
INSERT INTO tab01 values(20, 1100);
INSERT INTO tab01 values(30, 1200);
select * from tab01;
select decode(eno,
    10, SAL * 1.1, -- 10������ ���ʽ� 10�ۼ�Ʈ
    20, SAL * 1.2,
    30,SAL * 1.3) 
    from tab01;
/*
switch (eno){
    case 10:
        'ȣ����1',
    break;
}
*/
/*
--3)
select decode(floor(eno/3),
    0, sal * 1.1, -- 3���� �������� �޿� ���Ǵ� ��
    1, sal * 1.2,
    2,sal * 1.3) 
from tab01;
    
--4) case when then
select 
    case eno
        when 10 then sal * 1.1
        when 20 then sal * 1.2
        when 30 then sal * 1.3
    end
from tab01;
*/

-- �����Լ� : count(), sum(), max(), min(), avg()
-- ���
-- �л� : variance, ǥ������ : stddev
-- ������� 1���̴�. >> ����
-- �ʵ��� �Բ� ��� �� �� ����.
-- ��) select eno, count(eno) 
--�ʵ��� �Բ� ����� �� �ִ� ������ ����� group by�� �Բ� ����ϴ� ���̴�.
-- �����Լ��� WHERE������ ����� �� ����.
/*
purge RECYCLEBIN;
DROP TABLE tab01;
CREATE TABLE tab01(
    eno         number,
    sal         NUMBER
);

INSERT INTO tab01 values(10, 100);
INSERT INTO tab01 values(20, NULL);
INSERT INTO tab01 values(30, 300);
INSERT INTO tab01 values(40, 300);

select count(*) from tab01;
select count(sal) from tab01;
select count(distinct sal) from tab01;
select sum(eno) from tab01;
select sum(sal) from tab01;
select sum(distinct sal) from tab01;

select count(*)
from tab01
where sal = 300;

select count(*)
from tab01
where sal is not null;

select  
            count(eno), 
            sum(eno), 
            max(eno), 
            min(eno),
            avg(eno),
            variance(eno),
            stddev(eno)
from tab01;
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01;
CREATE TABLE tab01(
    eno        number,
    address varchar2(20),
    salary         NUMBER
);

INSERT INTO tab01 values(10, '����', 100);
INSERT INTO tab01 values(20, '�λ�', 200);
INSERT INTO tab01 values(20, '�뱸', 300);
INSERT INTO tab01 values(10, '����', 400);

-- �μ���ȣ�� 20�� ����� ����
-- �޿��� ���� ���� ����� �ݾ��� ? 300
-- �� ��� �̸��� ����?
select * from tab01 where eno = 20;
select max(salary) from tab01 where eno = 20;
-- �μ���ȣ�� 20 �� �޿��� ���� ���� ����� �ּ�
select address 
from tab01 
where salary = (
    select max(salary) 
    from tab01 
    where eno = 20);
-- �μ���ȣ�� 20�� ����� ��� �޿�
select avg(salary) from tab01 where eno = 20;
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01;
CREATE TABLE tab01(
    eno        number,
    address varchar2(20),
    salary         NUMBER
);

INSERT INTO tab01 values(10, '����', 100);
INSERT INTO tab01 values(20, '�λ�', 200);
INSERT INTO tab01 values(20, '�뱸', 300);
INSERT INTO tab01 values(10, '����', 400);
INSERT INTO tab01 values(10, '����', 400);

--�����Լ��� group by�� �Բ� ���ȴ�.
select eno �μ���ȣ, avg(salary) ��ձ޿� from tab01 group by eno;

-- group by : ~~ ����( �μ�����, ������, �а�����, )
-- having�� ������ �� �ִµ� ������ ����� ���� �� ����Ѵ�.
-- �׷쿡 ���� ������ ���� �� having�� ����Ѵ�.
-- �׷캰 ��ձ޿�, �׷캰 �����, �׷캰 �ִ� ����
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01;
CREATE TABLE tab01(
    eno             number,
    sal         NUMBER
);

INSERT INTO tab01 values(1, 800);
INSERT INTO tab01 values(2, 200);
INSERT INTO tab01 values(2, 400);
INSERT INTO tab01 values(1, 500);
INSERT INTO tab01 values(2, 300);

--ex1)
select eno, sum(sal)
from tab01
group by eno;

--ex2) �޿��� 300�̻��� �������� �׷캰 ������ ��´�.
select eno, sum(sal)
from tab01
where sal > 300 -- select�� �����Ѵ�.
group by eno;

--ex3) 
select eno, sum(sal)
from tab01
group by eno
having sum(sal) > 1000; --�׷��ε� ����� ����(����) �Ѵ�.

-- ex4)
select eno, sum(sal)
from tab01
where sal > 300 -- select�� �����Ѵ�.
group by eno
having sum(sal) > 1000 --�׷��ε� ����� ����(����) �Ѵ�.
order by eno;
*/
/*
set pagesize 44;
purge RECYCLEBIN;

DROP TABLE tab01;
CREATE TABLE tab01(
    name      varchar2(20),
    dept        varchar2(20),
    job         varchar2(20),
    salary      number
);

insert into tab01 values( 'ȫ�浿1', 'A�����', '����', 100);
insert into tab01 values( 'ȫ�浿2', 'A�����', '����', 200);
insert into tab01 values( 'ȫ�浿3', 'A�����', '����', 300);
insert into tab01 values( 'ȫ�浿4', 'A�����', '����', 400);
insert into tab01 values( 'ȫ�浿5', 'A�����', '����', 500);
insert into tab01 values( 'ȫ�浿6', 'A�����', '����', 600);
insert into tab01 values( 'ȫ�浿7', 'A�����', '����', 700);

insert into tab01 values( '�̼���1', 'B�����', '����', 100);
insert into tab01 values( '�̼���2', 'B�����', '����', 200);
insert into tab01 values( '�̼���3', 'B�����', '����', 300);
insert into tab01 values( '�̼���4', 'B�����', '����', 400);
insert into tab01 values( '�̼���5', 'B�����', '����', 500);
insert into tab01 values( '�̼���6', 'B�����', '����', 600);
insert into tab01 values( '�̼���7', 'B�����', '����', 700);
insert into tab01 values( '�̼���8', 'B�����', '����', 800);

insert into tab01 values( '���߱�1', 'C�����', '����', 100);
insert into tab01 values( '���߱�2', 'C�����', '����', 200);
insert into tab01 values( '���߱�3', 'C�����', '����', 300);
insert into tab01 values( '���߱�4', 'C�����', '����', 400);
insert into tab01 values( '���߱�5', 'C�����', '����', 500);
insert into tab01 values( '���߱�6', 'C�����', '����', 600);
insert into tab01 values( '���߱�7', 'C�����', '����', 700);
insert into tab01 values( '���߱�8', 'C�����', '����', 800);
insert into tab01 values( '���߱�9', 'C�����', '����', 900);

select * from tab01;

/*
A�����(7��) 		            B�����(8��) 		           C�����(9��)
����       ����   ����	    ����   ����   ����	        ����       ����    ����  ����
ȫ��1    ȫ��3 ȫ��6	    ����1 ����5 ����8	    �߱�1     �߱�4 �߱�5 �߱�8
ȫ��2    ȫ��4 ȫ��7	    ����2 ����6 		            �߱�2  	  �߱�6 �߱�9
             ȫ��5	    	    ����3 ����7		            �߱�3      �߱�7
                                    ����4
*/
/*
--1) 1�� �׷캰 ��� �������
select dept, count(*)
from tab01
group by dept;

--2) 2�� �׷캰 ��� �������
select dept,job, count(*)
from tab01
group by dept, job;

--3) rollup(��ü���� ��踦 �ѹ��� ������ �� �� ���)
select dept,job, count(*)
from tab01
group by rollup(dept, job);

--4)dept(�μ���) �Ѱ踸 ���´�.
select dept, job, count(*)
from tab01
group by dept, rollup(job);

--5)job(������) �Ѱ踸 ���´�.
select dept, job, count(*)
from tab01
group by job, rollup(dept);

--6) �Ʒ��� ���� ���Ͼ� �ϴ� ����
-- grouping sets �Լ��� �����ϴ�.
select dept, null, count(*)
from tab01
group by dept
union
select null, job, count(*)
from tab01
group by job;

select dept, job, count(*)
from tab01
group by grouping sets(dept, job);

select dept, job, 
    decode(
        grouping(job),
        0, job, 
        1, '�� �ο�'
        ), 
        count(*)
from tab01
group by rollup(dept, job);

select dept, grouping(dept) * 2, grouping(job), count(*)
from tab01
group by rollup(dept, job);

select dept, decode(grouping(dept) * 2 + grouping(job),
    0, job,
    1, '���ο�',
    2, dept,
    3, '��ü ���ο�' ), count(*)
from tab01
group by rollup(dept, job);

select dept, job, count(*)
from tab01
group by CUBE(dept, job)
order by dept;

select dept, 
        listagg(name, ', ')
        within group(order by null)
from tab01
group by dept
order by dept;

*/
/*
purge RECYCLEBIN;

DROP TABLE tab01;
CREATE TABLE tab01(
    dept        varchar2(20),
    job         varchar2(20),
    salary      number
);
insert into tab01 values( 'A�����', '����', 100);
insert into tab01 values( 'A�����', '����', 200);
insert into tab01 values( 'A�����', '����', 300);
insert into tab01 values( 'B�����', '����', 400);
insert into tab01 values( 'B�����', '����', 500);
insert into tab01 values( 'B�����', '����', 600);
insert into tab01 values( 'C�����', '����', 400);
insert into tab01 values( 'C�����', '����', 500);
insert into tab01 values( 'C�����', '����', 600);

select * from tab01
pivot(
    sum(salary) --�����Լ�
    for dept --A��(���)
    in('A�����', 'B�����', 'C�����') -- A�� �ʵ� �׸�
);
*/