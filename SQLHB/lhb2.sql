
SET PAGESIZE 44
purge RECYCLEBIN;
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name       varchar2(20),    -- 이름
    gno          number,           -- 번호 (부서번호, 사원번호) >> Primary Key(PK)//주키
    sal           number            -- 급여
);

DROP TABLE tab02;
CREATE TABLE tab02(
    gno          number,           --번호 >> Foreign Key(FK) // 외래키
    grade       varchar2(20)            --등급 ( 1등급, 2등급, A급, B급)
);

insert into tab01 values( '이순신', 1, 100);
insert into tab01 values( '안중근', 2, 200);
insert into tab01 values( '이순신', 2, 300);
insert into tab01 values( '윤봉길', 1, 400);

insert into tab02 values( 1, '서울');
insert into tab02 values( 2, '부산');
insert into tab02 values( 3, '청주');
*/
/*
-- 조인이 되면
-- 2개 이상의 테이블이 서로 연관 관계를 가질 때 관계형 데이터 베이스
-- 교차 조인(cross join) = 카테시안 곱
-- 교차조인 자체만으로는 사용하지 않는다. (절대로)
-- 테이블 row 갯수가 1000개 * 1000개 경우 기하급수적인 데이터가 생김(메모리가 감당 불가)
-- 성능 감소도 감당 불가
select * from tab01 cross join tab02; -- 명시적
select * from tab01, tab02; -- 묵시적

-- 같은것인가  묻는 조인 >> 등가조인
--등가 조인은 2개의 테이블에 반드시 일치하는 필드(열)이 있어야 한다.

-- T-SQL문법
select * from tab01, tab02 where tab01. gno = tab02.gno; 

-- 콤마 대신에 inner join, where대신에 on >> 내부 조인 == 등가 조인
-- ANSI SQL 조인 문법(표준 문법)
select * from tab01 inner join tab02 on tab01. gno = tab02.gno;
-- inner는 생략할 수 있다.
select * from tab01 join tab02 on tab01. gno = tab02.gno;

-- 공통되는 필드 알아서 제거해준다. >> 자연 조인
select * from tab01 natural join tab02;
--자연조인의 업그레이드 버젼 >> 자연조인 >> using 조인
-- 구분할 수 있는 필드명이 한개 이상일 때 사용한다. 
--자연조인상 겹치는 부분이 2개 이상일 때 명시해줄 필요성 때문에 using구문 사용
select * from tab01 join tab02 using(gno);
*/
/*
--테이블 명은 별칭을 사용할 수 있다. ( 사용하는게 대부분이다.)
-- [s1, s2] [s, t] [t1, t2]
select * from tab01  t1, tab02 t2 where t1. gno = t2.gno; 
select * from tab01  t1 inner join tab02 t2 on t1. gno = t2.gno; 

-- 조합해서 사용하는 코드( 출력개수 제한)
select * 
from tab01  t1, tab02 t2 
where t1. gno = t2.gno and ROWNUM <= 2;

-- 급여가 200이상인 분들의 고향은 어디인가 ?
select * 
from tab01  t1, tab02 t2 
where t1. gno = t2.gno -- 조인 조건
    and t1.sal > 200; -- 일반 조건
-- ture and false >> false와 같은 논리 연산으로 잘못 해석하지 말 것.

-- 두 테이블에서 부산 출신은 누구입니까?
select name
from tab01  t1, tab02 t2 
where t1.gno = t2.gno -- 조인 조건
    and t2.grade = '부산';
*/

-- 등가조인과 대비 되는것이 비등가 조인
-- 비등가 조인 : 등가조인이 아닌 조인은 비등가 조인이다.
--                      대소관계를 묻는 조인
--                      a >= 100 and a <= 200
--                      between
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name       varchar2(20),    -- 이름
    gno          number,           -- 번호 (부서번호, 사원번호) >> Primary Key(PK)//주키
    sal           number            -- 급여
);

DROP TABLE tab02;
CREATE TABLE tab02(
    grade       varchar2(20),            --등급 ( 1등급, 2등급, A급, B급)
    emin        number,
    emax        number
);
insert into tab01 values( '이순신', 1, 100);
insert into tab01 values( '안중근', 2, 200);
insert into tab01 values( '이순신', 2, 300);
insert into tab01 values( '윤봉길', 1, 400);

insert into tab02 values(  '1등급',100,200);
insert into tab02 values(  '2등급',201,300);
insert into tab02 values(  '3등급',301,400);
insert into tab02 values(  '4등급',401,500);

select * from tab01 t1, tab02 t2
where sal*1.2 >= emin and sal*1.2 <= emax;

select * from tab01 t1, tab02 t2
where sal between emin and emax;
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    id       number,    -- PK(사원번호)
    name          varchar2(20),           
    mgr           number            -- FK(사수번호)
);
-- 셀프조인
insert into tab01 values( 1, '이순신', NULL); -- 사장님
insert into tab01 values( 2, '안중근', 1); -- 직원
insert into tab01 values( 3, '윤봉길', 2); -- 직원
insert into tab01 values( 4, '홍길동', 1); -- 직원

select t1.id, t1.name,t1.mgr, t2.id,t2.name 사수이름,t2.mgr 
from tab01 t1, tab01 t2 -- 동일한 테이블을 서로 조인하기 위한 방안(등가 셀프 조인)
where t1.mgr = t2.id;
*/

--외부조인(outer join)
-- where A = B(+)
-- 좌측 테이블의 모든 결과를 가져온 후 우측테이블의 데이타 매칭
-- where A(+) = B
-- 위에것의 반대 개념
/*
DROP TABLE tab01;
DROP TABLE tab02;

CREATE TABLE tab01(
    id       number,    -- PK(사원번호)
    name          varchar2(20)           
);
CREATE TABLE tab02(
    id       number,    -- FK(사원번호)
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

--세미 조인 ( on, exists)를 사용한 조인
-- 1:n의 관계
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    id                number,    -- PK(사원번호)
    name          varchar2(20),
    dept            number
);
DROP TABLE tab02;
CREATE TABLE tab02(
    dept            number,
    name varchar2(20)
);
insert into tab01  values( 10, '홍길동1',1);
insert into tab01 values( 20, '홍길동2',1);
insert into tab01 values( 30, '홍길동3',2);
insert into tab01 values( 40, '홍길동4',2);

insert into tab02 values( 1, '컴공');
insert into tab02 values( 2, '경영');
insert into tab02 values( 3, '체육');

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

-- ex7) 수강신청을 한 학과만 출력하세요.
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

insert into menu values (1, '짜장');
insert into menu values (2, '우동');
insert into menu values (3, '냉면');
insert into menu values (4, '탕슉');
insert into menu values (5, '양장');

insert into sell values (1, 2, 1);
insert into sell values (2, 3, 2);
insert into sell values (3, 4, 2);
insert into sell values (4, 2, 2);
insert into sell values (5, 1, 1);
-- 판매된 음식의 종류를 출력하세요.
-- ex1)
select s.foodnum from sell s;
--결과 : (1, 2, 2, 2, 1)

select *
from menu d
--where d.foodnum = 1 or d.foodnum = 2;
--where d.foodnum in(1,2);
--where d.foodnum in (1, 2, 2, 2,1)
where d.foodnum in (select s.foodnum from sell s);

-- ex2) 세미조인이 성능은 더 좋다.(긍정으로 질문)- 판매된 목록
select *
from menu d
where exists(select s.foodnum  
        from sell s
        where d.foodnum = s.foodnum);
-- ex3) (부정으로 질문하면) 안티 조인 - 판매되지 않은 판매목록
select *
from menu d
where not exists(select s.foodnum  
        from sell s
        where d.foodnum = s.foodnum);
*/
        
-- 서브쿼리
-- 단일행 서브쿼리 : 서브쿼리의 실행결과가 1개일때
-- 다중행 서브쿼리 : 서브쿼리의 실행 결과가 n개 일때
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name                    varchar2(20),
    sal                         number
);

insert into tab01 values ('홍길동', 200);
insert into tab01 values ('이순신', 300);
insert into tab01 values ('안중근', 400);
insert into tab01 values ('윤봉길', 100);

-- 홍길동보다 급여가 높은 직원은?
--ex1) 홍길동의 급여는 얼마인가?
select sal 급여 from tab01
where name = '홍길동';

--ex2) 급여가 200보다 많은 직원은?
select * from tab01
where sal > 200;

-- ex3) 단일행 서브쿼리는 비교연산자만 사용 가능하다.
-- 서브쿼리의 결과가 2개 이상 나오는 쿼리는 대소 비교 연산자를 사용할 수 없다.
-- 홍길동이 2명있다면 쓰지 못하는 코드. <- 때문에 사원번호등으로 구분해서 바꾼 후 코드 사용해야한다.
select * --메인쿼리
from tab01
where sal > (
    select sal 급여 --단일 서브 쿼리
    from tab01
    where name = '홍길동');
    
-- 직원들의 평균 급여보다 높은 급여를 받는 직원을 출력하세요.
--직원들의 평균 급여가 궁금하다. 서브쿼리
-- 평균급여가 100원일때 100원보다 많이 받는 사람은? 주 쿼리
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

insert into tab01 values ('호랑이1', '서울', '개발');
insert into tab01 values ('호랑이2', '대전', '연구');
insert into tab01 values ('호랑이3', '대구', '지원');
insert into tab01 values ('호랑이4', '부산', '개발');
insert into tab01 values ('호랑이5', '서울', '연구');
insert into tab01 values ('호랑이6', '대전', '개발');
insert into tab01 values ('호랑이7', '대구', '기획');
insert into tab01 values ('호랑이8', '부산', '개발');
-- 호랑이 6번과 근무 도시가 다른 직원 중에 동일한 업무를 하는 사람은 ?
-- 호랑이 6번과 다른도시에 근무하면서 동일한 업무를 하는 직원은?
--1.호랑이 6번이 근무하는 도시
-- 2. 개발을 하는 사람은?
select city from tab01 where name = '호랑이6';
select job from tab01 where name = '호랑이6';

select * from tab01
where
    city != ( select city from tab01 where name = '호랑이6')
    and
    job = (select job from tab01 where name = '호랑이6');
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

insert into tab01 values ('호랑이1', 1);
insert into tab01 values ('호랑이2', 4);
insert into tab01 values ('호랑이3', 3);
insert into tab01 values ('호랑이4', 4);

insert into tab02 values (1, '서울');
insert into tab02 values (2, '대전');
insert into tab02 values (3, '대구');
insert into tab02 values (4, '부산');
-- 부산에 근무하는 직원은 ? (단, 등가조인은 사용하지 않는다.
SELECT name 직원 FROM tab01 
WHERE cityCode = (SELECT cityCode FROM tab02 WHERE city = '부산');
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

insert into tab01 values (1, '홍길동1', 10, 300);
insert into tab01 values (2, '홍길동2', 20, 400);
insert into tab01 values (3, '홍길동3', 20, 500);
insert into tab01 values (4, '홍길동4', 10, 600);

insert into tab02 values (10, '행정', '서울');
insert into tab02 values (20, '사무 ', '대전');
insert into tab02 values (30, '영업', '대구');

--  1) 평균급여보다 작은 직원은?
select ename 직원 
from tab01 
where sal < (
    select avg( sal ) 
    from tab01
);

-- 2) 평균 급여보다 작은 20번 부서의 직원은?
select ename 직원 
from tab01 
where 
    sal < (select avg( sal ) from tab01) 
    and 
    tab01.deptno = 20;
    
-- 3) 전체 사원의 평균 급여보다 작은 20번 부서의 사원의 상세 정보 검색
select * from tab01 a, tab02 b
where a.deptno = b.deptno
        and a.deptno = 20
        and a.sal < (select avg( sal ) from tab01);

-- select in ( select), any, all,exists ( 다중행 서브쿼리...)
-- 야구가 취미인 직원의 급여보다 급여가 많은 직원 검색
-- in(사원 10명 중에 야구가 취미인 직원이 3명)
-- 영업부 직원들의 관리자와 동일한 관리자로부터 관리 받는 직원은?
-- 영업부 직원 
-- 홍길동1 - 이순신1
-- 홍길동2 - 이순신1
-- 홍길동3 - 이순신2
-- 홍길동4 - 이순신2
-- 사수는 
-- 이순신1
-- 이순신2
-- 관리하는 직원은
-- + 개발부에서 직원들

-- 낚시가 취미인 직원의  나이와 동일한 나이의 직원 검색
DROP TABLE tab01;
CREATE TABLE tab01(
    ename varchar2(20),
    hobby varchar2(20),
    age number
);

insert into tab01 values ( '홍길동1', '낚시', 30);
insert into tab01 values ( '홍길동2', '등산', 40);
insert into tab01 values ( '홍길동3', '낚시', 50);
insert into tab01 values ( '홍길동4', '등산', 30);
insert into tab01 values ( '홍길동5', '수영', 40);
insert into tab01 values ( '홍길동6', '등산', 50);
insert into tab01 values ( '홍길동7', '낚시', 30);
insert into tab01 values ( '홍길동8', '등산', 40);
insert into tab01 values ( '홍길동9', '수영', 50);

select ename from tab01 where age in (select age from tab01 where hobby = '낚시');
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
-- 서브쿼리 = 인라인뷰
select * from (select  * from tab01 where sal > 20);

-- t1, t2는 with와 ; 까지가 유효범위
with
t1 as (select  * from tab01 where sal >= 20),
t2 as (select  * from tab01 where sal <= 20)
select *from t1, t2;


-- 누적값 볼 수 있다.
select sal, sum(sal) over(order by sal) from tab01;
*/
/*
DROP TABLE tab01;
CREATE TABLE tab01(
    name varchar2(20),
    sal number
);

insert into tab01 values ( '홍길동', 200);
insert into tab01 values ( '이순신', 300);
insert into tab01 values ( '안중근', 400);
insert into tab01 values ( '윤봉길', 100);

select * from tab01
where sal > (
    select sal
    from tab01
    where name = '홍길동'
);

--select * from user_views;
drop view view01;

create view view01 as  (
    select sal
    from tab01
    where name = '홍길동'
);
--select * from user_views;
select * from view01;
--될 것 같으나 안되는 코드
--select * from tab01 where sal > view01;
select * from tab01 where sal > (select * from view01);

-- 모든 것과 다른것을 같이 필드로 보고 싶다면?
--select rownum, * from tab01; (안된다)
select rownum, t1.*, sal, sal * 1.2 from tab01 t1
where rownum <= 2
order by name;
*/
/* 
id      name        salary
1       호랑이10   30
2       호랑이20   45
3       호랑이30   29
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
    '호랑이' || to_char(seq.currval * 10),
    ceil(DBMS_RANDOM.value(10, 100)) );
insert into tab01 values(
    seq.nextval,
    '호랑이' || to_char(seq.currval * 10),
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
insert into tab01 values( 1,  10, '홍길동1');
insert into tab01 values( 2,  10, '홍길동1'); -- 
insert into tab01 values( 3,  20, '홍길동2');
insert into tab01 values( 4,  20, '홍길동2'); --
insert into tab01 values( 5,  20, '홍길동2'); --
insert into tab01 values( 6,  30, '홍길동3');
insert into tab01 values( 7,  30, '홍길동3'); -- 
insert into tab01 values( 8,  40, '홍길동4');
insert into tab01 values( 9,  50, '홍길동5');
insert into tab01 values(10,  50, '홍길동5'); --

select * from tab01
where eid in (select min(eid) from tab01 group by eno);

select * from tab01
where not eid in (select min(eid) from tab01 group by eno);

-- group by 사용하지 않을 때
select * from tab01 a
where eid > (select min(eid) from tab01 b
                        where a.eno = b.eno -- 핵심 라인(테이블을 2개로 분할했기 때문에 가능한 기법)
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
--t3       110  -- 합
--hp      100 -- 합
--pp      150 -- 합
--t4       150 -- 합
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
--ex1) 날짜 데이터 출력
select * from tab01;
--ex2)
select TO_CHAR(saledate, 'YYYYMMDD') from tab01;

select sum(chulqty) from tab01;
-- ex3) 6월 5일 당일 총 판매량 출력
select sum(decode(saledate, 
                        '20/06/04', chulqty,
                        0)
)
from tab01;
-- ex4) 항상 당일 판매량...
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

-- 오늘을 기준으로 매출 합계
-- 유도과정
select ( '20210210' - TO_CHAR(SALEDATE, 'YYYYMMDD' ) ) A,
    7-( '20210210'-TO_CHAR(SALEDATE, 'YYYYMMDD' ) ) B,
    sign( 7 - ( '202010210'-TO_CHAR(SALEDATE, 'YYYYMMDD'))) C
from tab01;

select sum( decode
                        ( sign
                                ( 7 -('20210210' - TO_CHAR ( SALEDATE, 'YYYYMMDD'))), -- 일주일 합계
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
-- 년도별 판매갯수
select substr(saledate, 1, 2) as year , sum(chulqty)
from tab01
group by substr(saledate, 1, 2)
order by year;
*/
drop table tab01;
create table tab01(
    물품번호 number,
    물품이름 varchar2(20),
    물품단가 number
);
drop table tab02;
create table tab02(
    물품번호 number,
    판매수량 number
);
insert into tab01 values (1, '바나나', 1000);
insert into tab01 values (2, '오렌지', 2000);
select * from tab01;

insert into tab02 values (1, 1); -- 바나나 1개 판매
insert into tab02 values (1, 2); -- 바나나 2개 판매
insert into tab02 values (1, 3); -- 바나나 1개 판매
insert into tab02 values (2, 2); -- 오랜지 2개 판매
select * from tab02;

-- 바나나의 총 판매개수와 총 판매 금액을 출력하세요.
select sum(판매수량), sum(판매수량 * 물품단가)
from tab01 a, tab02 b
where a.물품번호 = b."물품번호"
and a."물품이름" = '바나나';

select a.물품이름, sum(판매수량), sum(판매수량 * 물품단가)
from tab01 a, tab02 b
where a.물품번호  =  b.물품번호
group by a.물품이름
having a.물품이름 = '바나나';

COMMIT;