-- 주석 문장

/*
-- sql 문장이다.
-- *(아스트릭) : 와일드카드( 모든 ) * ?
-- 실행시키는 방법은 2가지
    -- F5
    --ctrl + enter : 결과값을 테이블 형식으로 보여준다.

-- C에서 ' '은 문자를 의미하고 " "은 문자열을 의미한다.
-- 오라클에서는 ' ' 무조껀 문자열 . 문자열 표시는 ' '이다.
-- SET PAGESIZE 14; // 14 - 4 = 10 <- 10줄씩 끊어 읽어라
-- 문자열을 다루는 타입은 VARCHAR2 : 바차2
-- ID , Name, Alias, Password, Sex, Address, city, PostCode
-- Country, Birthday, Photo(파일명), Salary, Phone 
-- 쿼리문은 대소문자 구분을 하지 않지만, 대문자가 관례이다.

-- 테이블을 만든다.( SQL Developer에서 테이블을 쉽게 만들 수 있지만, 별 의미 없다.)
-- 반드시 쿼리문은 세미콜론으로 끝나야 한다.
*/
/*
--모든 테이블 목록을 보여주세요
--SELECT * FROM TAB;

--휴지통을 비워 주세요
PURGE RECYCLEBIN;

DROP TABLE tab01;
--테이블 생성해주세요.
CREATE TABLE tab01(
    age NUMBER              -- 컬럼명 타입,  
);
--별로 중요하지 않다.(테이블 이름을 갱신할 수 있다.)
rename tab01 to tab02; -- old name to new name

-- 휴지통을 보여주세요.
SHOW RECYCLEBIN;

--테이블 봅시다
SELECT * FROM TAB;

-- 물리적으로 저장되는것
COMMIT; 
*/
/*
PURGE RECYCLEBIN;
DROP TABLE tab01;
-- 테이블 컬럼을 CRUD 할 수 있다.
CREATE TABLE tab01(
    ID          VARCHAR2 (20), -- 설명을...주석으로 작성하는 것이 정석
    NAME    VARCHAR2 (20),
    age        NUMBER              -- 컬럼명 타입,  
);


--DESC tab01;
--Create
INSERT INTO tab01(id, name, age) VALUES( 1, '호랑이1', 1000);
INSERT INTO tab01(id, name, age) VALUES( 2, '호랑이2', 2000);
INSERT INTO tab01(id, name, age) VALUES( 3, '호랑이3', 3000);

-- Update
-- if 대신에 where가 사용되고
-- 비교연산자 == 대신에 (=)가 사용된다.
UPDATE tab01 SET age = 4000,  name = '독수리' WHERE id = 3;

--Delete
DELETE FROM tab01 WHERE id = 2;

--Read
--테이블명에 있는 모든것을 보여주세요.
SELECT * FROM tab01;

COMMIT; 
*/

/* -----------------------------------------------------------
PURGE RECYCLEBIN;
DROP TABLE emp1;
-- 테이블 컬럼을 CRUD 할 수 있다.
CREATE TABLE emp1(
    eno            NUMBER (4), -- 사원번호(employee)
    ename       VARCHAR2 (20),
    sal             NUMBER             -- 급여
);
--ex1) 명시적 방법
--INSERT INTO emp1 (eno, ename, sal) VALUES ( 1009, '독수리', 500);

--ex2) 묵시적 방법
--컬럼개수만큼 모두 입력해야 한다.
INSERT INTO emp1 VALUES ( 1001, '코끼리', 350);

--ex3) 실패코드
--INSERT INTO emp1 VALUES ( '코끼리1', 350);

--ex4) 필요한 필드만 입력이 가능하다
INSERT INTO emp1 (ename, sal) VALUES ( '호랑이', 500);

--ex5) 연산식을 사용할 수 있다.
INSERT INTO emp1 VALUES (1000+4, '까마귀1', 350 * 1.2);

--ex6) NULL값을 입력할 수 있다.
INSERT INTO emp1 VALUES (NULL, '까마귀2', 350 * 1.2);

--ex7) 결과적으로는 사용 안한다.
-- 문자열 입력할때는 ' ' 사이에는 문자열을 입력해야한다.
--sqlplus에서 하면 안된다.(정규문법 아님)
--INSERT INTO emp1 VALUES (&a, &b, &c);
--INSERT INTO emp1 VALUES (&a, '&b', &c);
--------------------------------------------------------------------------------
--ex1) 테이블 목록 모든것을 본다.
--SELECT * FROM tab;

--ex2) 테이블 내용 모든것을 본다.
SELECT * FROM emp1;

--ex3) row의 갯수를 알고 싶을 때
SELECT count(*) from emp1;

--ex4) null값을 제외한 컬럼지정 row의 갯수
SELECT count(eno) from emp1;

--ex5) 선택적으로 필요한 필드만 얻는다.
SELECT eno,sal FROM emp1;

--ex6) 컬럼의 이름 변경(별칭) >> 자주 사용된다.
SELECT eno AS 사번,ename AS 이름, sal AS 급여 FROM emp1;
--가독성 떨어지는 코드
SELECT eno 사번,ename 이름, sal 급여 FROM emp1;

--ex7) 별칭 사이에 공백이 있을때는 " " 을 사용한다.
SELECT eno AS "사  번",ename AS 이름, sal AS 급여 FROM emp1;

--ex8) 문자열 연결( 컬럼 연결 )
--|| 을 파이프 연산이라고 한다.
SELECT ( eno || ename ) , sal FROM emp1;

--ex9) 별칭과 응용하게 되면
SELECT ( eno || ename ) AS 사번이름, sal AS 급여 FROM emp1;

--ex10) 연속해서 조합이 가능하다. 
SELECT eno, eno, ( eno || ename ) AS 사번이름, sal AS 급여 FROM emp1;

--ex11) Distinct 중복되지 않게 선택 출력
INSERT INTO emp1 VALUES (1111, '독수리', 1350);
INSERT INTO emp1 VALUES (1221, '호랑이', 2350);
SELECT * FROM emp1;
SELECT DISTINCT(ename) FROM emp1;

--ex12) Distinct 된 결과의 개수를 얻는다.
-- 결과는 1개가 나온다.
SELECT count (DISTINCT(ename)) FROM emp1;

--ex13) 결과가 1개 나오는 것과 N개 나오는 select는 사용 할 수가 없다.
-- row 개수가 다르게 나타나는 문장은 사용할 수 없다.
--SELECT eno, count (DISTINCT(ename)) FROM emp1;

--ex14) 필드에도 수식을 사용할 수 있다.
-- NULL 데이터는 연산식에서 무시된다.
SELECT sal AS 급여, sal*1.2 AS 실수령액, sal*1.2 - sal AS 보너스 FROM emp1;
SELECT eno, sal AS 월급, sal*12 AS 연봉 FROM emp1;

--ex14) 테이블 사용하지 않고 dual 테이블을 사용할 수 있다.
--테스트 용도로 많이 사용된다.(임시테이블)
-- 산술 연산
--mod 나머지 , floor 몫
select 8+3, 8-3, 8*3, 11/3, floor(11/ 3), mod(11, 3), floor(-1.5)  from dual;

COMMIT; 
-------------------------------------------------------------------------------------------------*/
/*
PURGE RECYCLEBIN;
DROP TABLE emp1;
-- 테이블 컬럼을 CRUD 할 수 있다.
CREATE TABLE emp1(
    eno            NUMBER (4), -- 사원번호(employee)
    ename       VARCHAR2 (20),
    sal             NUMBER             -- 급여
);

INSERT INTO emp1 VALUES ( 1009, '독수리', 500);
INSERT INTO emp1 VALUES ( 1001, '호랑이', 200);
INSERT INTO emp1 VALUES ( 1002, '호랑이', 200);
INSERT INTO emp1 VALUES ( 1003, '까마귀', 150);
INSERT INTO emp1 VALUES ( 1004, '라이언', 150);
INSERT INTO emp1 VALUES ( 1005, '호랑이', 350);
--ex16) 정렬( 실전에서 사용하기가 아주 불편하다. )
-- 서버 비용이 발생한다.
-- 100만개의 데이타를 정렬해서 10개만 주세요.
SELECT * FROM emp1;
SELECT * FROM emp1 order by sal asc; -- ascanding
SELECT * FROM emp1 order by sal desc; -- descanding
--옳지 않은 방법이지만...(eno : 1, ename : 2, sal : 3)
SELECT * FROM emp1 order by 3; 
SELECT * FROM emp1 order by sal asc, eno desc;
SELECT * FROM emp1 order by sal, eno desc;
SELECT * FROM emp1 order by sal, eno;
*/

PURGE RECYCLEBIN;
DROP TABLE emp1;
-- 테이블 컬럼을 CRUD 할 수 있다.
CREATE TABLE emp1(
    ename       VARCHAR2 (20),
    kor             NUMBER,
    eng             NUMBER,
    mat             NUMBER
);

INSERT INTO emp1 VALUES (  '독수리', 50, 33, 52);
INSERT INTO emp1 VALUES (  '호랑이1', 20,44, 23);
INSERT INTO emp1 VALUES (  '호랑이2', 20, 55,98);
INSERT INTO emp1 VALUES ( '까마귀', 15,66,54);
INSERT INTO emp1 VALUES ( '라이언', 15,11,88);
INSERT INTO emp1 VALUES ( '호랑이3', 35,3,99);
--ex17) 점수 합에 대한 정렬
SELECT * FROM emp1;
-- 방법 1
SELECT ename, kor, eng, mat, (kor + eng + mat) 
FROM emp1 
ORDER BY (kor + eng + mat);
-- 방법 2
SELECT ename, kor, eng, mat, (kor + eng + mat) AS sumsum 
FROM emp1 
ORDER BY (sumsum) desc;

-- ex18) 비교연산 >, <, >=, <=, =(주의), != ( <>, ^=)
SELECT * FROM emp1 where kor > 40;
SELECT ename FROM emp1 where kor > 40;

SELECT ename, (kor + eng + mat) 합산점수 
FROM emp1 
where (kor+eng+mat) > 120 
ORDER BY ename;

COMMIT; 