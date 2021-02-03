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
INSERT INTO emp1 VALUES (  'ȣ����1', 20,44, 23);
INSERT INTO emp1 VALUES (  'ȣ����2', 20, 55,98);
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

COMMIT; 