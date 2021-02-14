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
/*
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
INSERT INTO emp1 VALUES (  '호랑이1', 60,44, 23);
INSERT INTO emp1 VALUES (  '호랑이2', 80, 55,98);
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

--ex19) where절에서는 별칭을 사용할 수 없다.
--SELECT kor AS aliaskor 
--FROM emp1 
--WHERE aliaskor > 50;

--ex20) where절에서는 별칭을 사용할 수 없다.
--SELECT
--컬럼         -- 별칭 사용(O)
--FROM 테이블명
--WHERE       -- 별칭 사용(X)
--GROUP BY    -- 별칭 사용(O)
--HAVING      -- 별칭 사용(O)
--ORDER BY    -- 별칭 사용(O)
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

INSERT INTO emp1 VALUES (  '독수리', 50, 33, 52);
INSERT INTO emp1 VALUES (  '호랑이1', 60,44, 23);
INSERT INTO emp1 VALUES (  '호랑이2', 80, 55,98);
INSERT INTO emp1 VALUES ( '까마귀', 15,66,54);
INSERT INTO emp1 VALUES ( '라이언', 15,11,88);
INSERT INTO emp1 VALUES ( '호랑이3', 35,3,99);

--ex21)테이블명 대신에 쿼리문을 사용할 수 있다.
-- 인라인 뷰, 서브쿼리
SELECT COUNT(*) FROM emp1;
SELECT COUNT(*) FROM (SELECT * FROM emp1 WHERE kor > 50);
-- 위 문장과 동일
SELECT COUNT(*) FROM emp1 WHERE kor > 50;

--ex22) AND, OR, NOT 사용
SELECT * FROM emp1
WHERE kor > 30 AND kor < 80;

SELECT * FROM emp1
WHERE kor > 30 OR ename = '까마귀';

SELECT * FROM emp1
WHERE NOT(kor > 30 AND kor < 80);

--ex23)IN은 (= OR)와 완전 동격
SELECT * FROM emp1
WHERE kor = 50 OR kor = 15 OR kor = 40;

SELECT * FROM emp1
WHERE kor NOT IN(50, 15, 40);
--WHERE kor NOT IN(가변적일 수 있다.);
--WHERE kor NOT IN(SELECT 문이 들어 올 수 있다.);
*/
/*
PURGE RECYCLEBIN;
DROP TABLE TAB01;

CREATE TABLE TAB01(
    ename       VARCHAR2 (20),
    mt          VARCHAR2 (20)
);

INSERT INTO TAB01 VALUES (  '호랑이1', '북한산');
INSERT INTO TAB01 VALUES (  '호랑이2', '도봉산');
INSERT INTO TAB01 VALUES (  '호랑이3', '북한산');
INSERT INTO TAB01 VALUES (  '호랑이4', '관악산');
INSERT INTO TAB01 VALUES (  '호랑이5', '지리산');
SELECT ename From TAB01 WHERE mt = '도봉산' OR mt = '지리산';
SELECT ename From TAB01 WHERE mt IN ('도봉산' , '지리산');
-- 산의 높이가 상위 10위 안에 들어가는 산을 다녀온 고객의 명단을 출력하세요.
DROP TABLE TAB02;
CREATE TABLE TAB02(
    mt       VARCHAR2 (20),
    height          NUMBER,
    national        국적
);

INSERT INTO TAB02 VALUES ( '북한산', 1000);
INSERT INTO TAB02 VALUES ( '도봉산', 2000);
INSERT INTO TAB02 VALUES ( '관악산', 1500);
INSERT INTO TAB02 VALUES ( '지리산', 1800);

-- 산의 높이가 1600 이상
--select mt from tb02 where height > 1600;
-- 산의 높이가 1600 보다 높은 산을 다녀온 고객의 명단을 출력하세요.
-- 예시)산의 높이가 상위 10위 안에 들어가는 산을 다녀온 고객의 랜튼을 한 차번호를 출력하세요.
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
INSERT INTO emp1 VALUES (  '호랑이2', null, 55,98);
INSERT INTO emp1 VALUES ( '까마귀', 15,null,54);
INSERT INTO emp1 VALUES ( '라이언', null,11,88);
INSERT INTO emp1 VALUES ( '호랑이3', 35,3,99);
--ex25)
SELECT * FROM emp1
WHERE ename like '호%';

--ex26) null
--not in
--not between
--not like
--is null >> 데이터 값이 null인가...
--is not null

--ex27) null이 필요한 경우
-- 원본 데이터에서 데이타가 소실 혹은 없는 경우
-- 은행 고객인데 통장 개설을 하지 않은 고객
-- 미혼인 고객의 결혼 기념일
-- 비밀번호 찾기를 설정하지 않았을때
-- 미성년자의 출신대학

--ex28)일단 오류가 난다.
SELECT * FROM emp1
--WHERE kor = null; -- 주의 해야 한다.(사용하지 않는 케이스)
--WHERE kor is null; --(사용하는 케이스)
WHERE kor is not null; --(사용하는 케이스)

--ex29)
SELECT * FROM emp1
WHERE kor is null or eng is null;

--ex30) 문자열에 아무것도 안들어가('') 있으면 null처리 된다.
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

INSERT INTO emp1 VALUES (  '일길동', '서울');
INSERT INTO emp1 VALUES (  '이길동', '대전');
INSERT INTO emp1 VALUES (  '삼길동', '서울');
INSERT INTO emp1 VALUES (  '사길동', '대전');
INSERT INTO emp1 VALUES (  '오길동', '서울');
INSERT INTO emp1 VALUES (  '육길동', '대구');

-- ex31) 삼길동의 고향과 동일한 고향을 가진 사람의 명단을 출력하세요.
-- 테이블에도 닉네임을 사용할 수 있다.
-- 임시테이블을 생성하기 위하여 서브쿼리가 사용되었다.
SELECT s1.ename FROM emp1 s1, (SELECT address FROM emp1 where ename = '삼길동') s2
WHERE s1.address = s2.address;

-- ex32)max, min
-- ( > all ), ( < any ) >> max에 대한 것을 찾는다는 의미
-- ( < all ), ( > any ) >> min에 대한 것을 찾는다는 의미
--WHERE SALARY > 200 OR SALARY > 300 OR SALARY > 400 (쓸모없는 문장인 것 같지만...)
--SALARY가 가변적으로 들어올 상황이라면 이야기는 달라진다. 때문에 ANY를 사용하는 것이다.
-- 200, 300, 400 중에서 최소값보다 큰것인가 묻는것이다.
-- IN하고 관계가 있는 듯 하지만 IN은 =가를 물어 본 것(때문에 IN과는 상관이 전혀 없다.)

--WHERE SALARY > ANY(200, 300, 400) >> 윗 문장과 완전 동일한 문장.
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
    dept         NUMBER, -- 부서번호 (기획부서, 개발부서, 영업부서, 총괄부서, 홍보부서)
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

-- 20번 부서에 급여를 가장 많이 받는 사람보다 급여가 적은 직원들을 모두 출력하세요.
--접근(1) 20번 부서의 급여를 검색한다.
SELECT sal FROM tab1 WHERE dept = 20; -- 200, 600, 350
--접근(2)
SELECT * FROM tab1 WHERE sal < ANY(200, 600, 350);
--접근(3)
SELECT *
FROM tab1
WHERE sal < ANY(
    SELECT sal
    FROM tab1
    WHERE dept = 20
);
-- 컴공과에서 제일 낮은 점수를 받은 학생보다 못한 다른학과 학생들은 누구냐 ?
--    컴공 40
--    컴공 20 --> 컴공 중에서 제일 낮은 학생
--    컴공 50
--    중국 80
--    중국 70
--    중국 10 ->> 결과
--    일어 40
--    일어 05 ->> 결과
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
INSERT INTO tab01 VALUES (50,'원숭',300);
--ex31)
--결과만 대문자로 변환하지 원본데이터가 대문자가 된거는 아니다.
select upper(ename) from tab01;
select lower(ename) from tab01;
select initcap(ename) from tab01;
select * from tab01 where upper(ename) = upper('TIGER2');
select * from tab01 where lower(ename) like 'tiger%';
--ex31) 몇글자인가
select length(ename), lengthb(ename) from tab01;
select * from tab01 where length(ename) > 3;
--이름이 외자인 경우를 찾아라
select * from tab01 where length(ename) <=2;
--이름이 3자리가 아닌 경우를 찾아라
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
--substr : 특정부분의 문자열을 분리할때
--첫번째 인덱스는 1이다
select substr(tel, 5, 3) , substr(tel,5) from tab02;
DROP TABLE tab03; 
CREATE TABLE tab03(             
    eno         number,
    tel        varchar2(20)
);
INSERT INTO tab03 VALUES (10,'호랑이만세1편.');
INSERT INTO tab03 VALUES (20,'호랑이끼리만세2편..');
INSERT INTO tab03 VALUES (30,'독수리호랑이만세3편...');
INSERT INTO tab03 VALUES (40,'12345678호랑이...');
INSERT INTO tab03 VALUES (50,'독수리만세3편...');
--영화제목을 모두출력하세요 단 제목이 길때는 앞 4자리만 출력
select substr(tel,1,4), length(tel) from tab03;
select substr(tel,length(tel)-4) from tab03;
-- instr
--select instr(tel, '호랑이') from tab03;
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

INSERT INTO tab01 VALUES (10,'호랑이-만세');
INSERT INTO tab01 VALUES (20,'코호랑이만-세');
INSERT INTO tab01 VALUES (30,'독수호랑이');
INSERT INTO tab01 VALUES (30,'독수_호랑이');

SELECT REPLACE(ename, '호랑이', '코끼리') from tab01;
SELECT REPLACE(ename, '-', ' ') from tab01;
SELECT REPLACE(ename, '-', '') from tab01;

INSERT INTO tab01 VALUES (10,'tiger1');
INSERT INTO tab01 VALUES (20,'tiger2');
INSERT INTO tab01 VALUES (30,'tiger3');
INSERT INTO tab01 VALUES (30,'tiger4');
-- rpad, lpad(right, left)
-- 남은 공간은 전부 * 채움
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
INSERT INTO tab01 VALUES (10,'호랑이');
INSERT INTO tab01 VALUES (20,'코끼리');
INSERT INTO tab01 VALUES (30,'독수리');

SELECT CONCAT(ename, ':') from tab01;
SELECT CONCAT(eno, ename) from tab01;
SELECT CONCAT(eno, CONCAT(':',ename)) from tab01;
SELECT eno || (':' || ename) 연결 from tab01;
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01; 
CREATE TABLE tab01(             
    eno         number,
    ename        varchar2(20)
);
--trim(세부조건 ltrim, rtrim )
INSERT INTO tab01 VALUES (10,' 호랑이 ');
INSERT INTO tab01 VALUES (20,'코 끼 리');
INSERT INTO tab01 VALUES (30,'_독수리_');
INSERT INTO tab01 VALUES (30,'독_수_리');
-- 양쪽 끝에 있는 스페이스를 제거한다.
select trim(ename) from tab01;
-- 양쪽 끝에 있는 _ 제거
SELECT TRIM('_' FROM ename) from tab01;
-- id를 입력하는데
-- tiger
*/
/*
purge RECYCLEBIN;
DROP TABLE tab01; 
CREATE TABLE tab01(             
    eno         number,
    ename        varchar2(20)
);

-- ~.4 내림 .5~ 올림
select round(1234.4),round(1234.5) from dual;
-- 소숫점 2번째까지 지워버림
select round(1234.5678, 2) from dual;
-- 2번째 자리숫자까지 올려버림
select round(1234, -2) from dual;
-- 1번째 자리숫자까지 올리거나 내려버림
select round(1234, -1), round(1235, -1) from dual;

--trunc(반올림 없이 무조껀 잘라버림)
select trunc(1234.4), trunc(1234.5) from dual;
--trunc(반올림 없이 첫번째 숫자까지 잘라버림)
select trunc(1234, -1), trunc(1235, -1) from dual;

--trunc
select ceil(3.14), floor(3.14), ceil(-3.14), floor(-3.14) from dual;
select floor(7/3), mod(7,3) from dual;

select 10+20 from dual;
-- 일반적인 프로그램에서는 문자 + 숫자이면 문자가 된다.
-- 오라클데이터베이스에서는 위와는 다르게 숫자가 된다.
select '10' + '20' from dual;
-- 주의 : 성립이 안된다(성립 시키기 위해서 파이프 연산을 한다.)
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

INSERT INTO tab01 values(null, '호랑이');
INSERT INTO tab01 values(30, NULL);

SELECT 100 + eno, ename from tab01;
--nvl을 사용하면 null이 연산에 참여할 수 있다.(널이 있다명 0 혹은 '익명으로 표시')
SELECT 100 + nvl(eno, 0), nvl(ename, '익명') ename from tab01;
-- 널이면 20이 선택되고 널이 아니면 10이 선택된 상황(문자열도 동일한 원리)
SELECT 100 + nvl2(eno, 10, 20), nvl2(ename, ename, '익명') ename from tab01;
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

--양쪽의 필드와 타입이 일치해야 사용할 수 있다.
select  ename from tab01
union -- 합집합( 중복된 데이타는 1개만 남기고 제거된다.)
select  ename from tab02;

select  ename from tab01
union all -- 합집합( 중복된 데이타는 1개만 남기고 제거된다.)
select  ename from tab02;

--교집합데이터
select  ename from tab01
intersect -- 교집합( 중복된 데이타는 1개만 남기고 제거된다.)
select  ename from tab02;

--교집합데이터
select  ename from tab01
intersect -- 교집합( 중복된 데이타는 1개만 남기고 제거된다.)
select  ename from tab02;

select  ename from tab01
minus -- 차집합
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

--보통 필터링 조건을 활용하여 union 사용한다.)
--일치하지 않는 경우에 null로 대체할 수 있다.
--union은 한번 이상 사용할 수 있다.

--ex) 생산자의 이름 + 소비자의 이름
select  ename from tab01 where eno <= 20
union
select  ename  from tab02 where eno >= 30;
*/
--purge RECYCLEBIN;

--decode(실전에서 자주 나온다.)
-- switch문과 유사하다 goto문과 비슷하다.
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
    10, '호랑이1',
    20, '호랑이2', 
    30 , '호랑이3') from tab01;
*/
/*
switch (eno){
    case 10:
        '호랑이1',
    break;
}
*/

/*
purge RECYCLEBIN;

--decode(실전에서 자주 나온다.)
-- switch문과 유사하다 goto문과 비슷하다.

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
    10, SAL * 1.1, -- 10년차는 보너스 10퍼센트
    20, SAL * 1.2,
    30,SAL * 1.3) 
    from tab01;
/*
switch (eno){
    case 10:
        '호랑이1',
    break;
}
*/
/*
--3)
select decode(floor(eno/3),
    0, sal * 1.1, -- 3년차 기준으로 급여 계산되는 논리
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

-- 집계함수 : count(), sum(), max(), min(), avg()
-- 통계
-- 분산 : variance, 표준편차 : stddev
-- 결과값은 1개이다. >> 주의
-- 필드명과 함께 사용 할 수 없다.
-- 예) select eno, count(eno) 
--필드명과 함께 사용할 수 있는 유일한 방법은 group by와 함께 사용하는 것이다.
-- 집계함수는 WHERE절에서 사용할 수 없다.
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

INSERT INTO tab01 values(10, '서울', 100);
INSERT INTO tab01 values(20, '부산', 200);
INSERT INTO tab01 values(20, '대구', 300);
INSERT INTO tab01 values(10, '서울', 400);

-- 부서번호가 20인 사원에 조건
-- 급여가 가장 많은 사람의 금액은 ? 300
-- 그 사람 이름이 뭔데?
select * from tab01 where eno = 20;
select max(salary) from tab01 where eno = 20;
-- 부서번호가 20 중 급여가 가장 높은 사원의 주소
select address 
from tab01 
where salary = (
    select max(salary) 
    from tab01 
    where eno = 20);
-- 부서번호가 20인 사람의 평균 급여
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

INSERT INTO tab01 values(10, '서울', 100);
INSERT INTO tab01 values(20, '부산', 200);
INSERT INTO tab01 values(20, '대구', 300);
INSERT INTO tab01 values(10, '서울', 400);
INSERT INTO tab01 values(10, '서울', 400);

--집계함수와 group by는 함께 사용된다.
select eno 부서번호, avg(salary) 평균급여 from tab01 group by eno;

-- group by : ~~ 별로( 부서별로, 팀별로, 학과별로, )
-- having을 동반할 수 있는데 조건을 만들고 싶을 때 사용한다.
-- 그룹에 대한 조건을 따질 때 having을 사용한다.
-- 그룹별 평균급여, 그룹별 사원수, 그룹별 최대 연봉
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

--ex2) 급여가 300이상인 직원들의 그룹별 정보를 얻는다.
select eno, sum(sal)
from tab01
where sal > 300 -- select를 제한한다.
group by eno;

--ex3) 
select eno, sum(sal)
from tab01
group by eno
having sum(sal) > 1000; --그룹핑된 결과를 제한(조건) 한다.

-- ex4)
select eno, sum(sal)
from tab01
where sal > 300 -- select를 제한한다.
group by eno
having sum(sal) > 1000 --그룹핑된 결과를 제한(조건) 한다.
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

insert into tab01 values( '홍길동1', 'A사업부', '개발', 100);
insert into tab01 values( '홍길동2', 'A사업부', '개발', 200);
insert into tab01 values( '홍길동3', 'A사업부', '생산', 300);
insert into tab01 values( '홍길동4', 'A사업부', '생산', 400);
insert into tab01 values( '홍길동5', 'A사업부', '생산', 500);
insert into tab01 values( '홍길동6', 'A사업부', '지원', 600);
insert into tab01 values( '홍길동7', 'A사업부', '지원', 700);

insert into tab01 values( '이순신1', 'B사업부', '연구', 100);
insert into tab01 values( '이순신2', 'B사업부', '연구', 200);
insert into tab01 values( '이순신3', 'B사업부', '연구', 300);
insert into tab01 values( '이순신4', 'B사업부', '연구', 400);
insert into tab01 values( '이순신5', 'B사업부', '생산', 500);
insert into tab01 values( '이순신6', 'B사업부', '생산', 600);
insert into tab01 values( '이순신7', 'B사업부', '생산', 700);
insert into tab01 values( '이순신8', 'B사업부', '지원', 800);

insert into tab01 values( '안중근1', 'C사업부', '연구', 100);
insert into tab01 values( '안중근2', 'C사업부', '연구', 200);
insert into tab01 values( '안중근3', 'C사업부', '연구', 300);
insert into tab01 values( '안중근4', 'C사업부', '개발', 400);
insert into tab01 values( '안중근5', 'C사업부', '생산', 500);
insert into tab01 values( '안중근6', 'C사업부', '생산', 600);
insert into tab01 values( '안중근7', 'C사업부', '생산', 700);
insert into tab01 values( '안중근8', 'C사업부', '지원', 800);
insert into tab01 values( '안중근9', 'C사업부', '지원', 900);

select * from tab01;

/*
A사업부(7명) 		            B사업부(8명) 		           C사업부(9명)
개발       생산   지원	    연구   생산   지원	        연구       개발    생산  지원
홍길1    홍길3 홍길6	    순신1 순신5 순신8	    중근1     중근4 중근5 중근8
홍길2    홍길4 홍길7	    순신2 순신6 		            중근2  	  중근6 중근9
             홍길5	    	    순신3 순신7		            중근3      중근7
                                    순신4
*/
/*
--1) 1차 그룹별 사람 몇명인지
select dept, count(*)
from tab01
group by dept;

--2) 2차 그룹별 사람 몇명인지
select dept,job, count(*)
from tab01
group by dept, job;

--3) rollup(전체적인 통계를 한번에 보고자 할 때 사용)
select dept,job, count(*)
from tab01
group by rollup(dept, job);

--4)dept(부서별) 총계만 나온다.
select dept, job, count(*)
from tab01
group by dept, rollup(job);

--5)job(업무별) 총계만 나온다.
select dept, job, count(*)
from tab01
group by job, rollup(dept);

--6) 아래와 같이 유니언 하는 것은
-- grouping sets 함수와 동일하다.
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
        1, '총 인원'
        ), 
        count(*)
from tab01
group by rollup(dept, job);

select dept, grouping(dept) * 2, grouping(job), count(*)
from tab01
group by rollup(dept, job);

select dept, decode(grouping(dept) * 2 + grouping(job),
    0, job,
    1, '총인원',
    2, dept,
    3, '전체 총인원' ), count(*)
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
insert into tab01 values( 'A사업부', '생산', 100);
insert into tab01 values( 'A사업부', '지원', 200);
insert into tab01 values( 'A사업부', '생산', 300);
insert into tab01 values( 'B사업부', '지원', 400);
insert into tab01 values( 'B사업부', '생산', 500);
insert into tab01 values( 'B사업부', '지원', 600);
insert into tab01 values( 'C사업부', '생산', 400);
insert into tab01 values( 'C사업부', '지원', 500);
insert into tab01 values( 'C사업부', '생산', 600);

select * from tab01
pivot(
    sum(salary) --집계함수
    for dept --A별(상단)
    in('A사업부', 'B사업부', 'C사업부') -- A별 필드 항목
);
*/