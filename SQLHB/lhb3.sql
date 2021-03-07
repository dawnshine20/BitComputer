PURGE RECYCLEBIN;
DROP TABLE tab01;

CREATE TABLE tab01(
    name          VARCHAR2 (20), 
    age             NUMBER,
    salary          NUMBER              
);

--INSERT INTO tab01 VALUES( '홍길동', 10, 1000);
--INSERT INTO tab01 VALUES( '이순신', 20, 2000);
--INSERT INTO tab01 VALUES( '유관순', 30, 3000);
--INSERT INTO tab01 VALUES( '안중근', 40, 4000);
--INSERT INTO tab01 VALUES( '윤봉길', 50, 6000);
select count(*) from tab01;
SELECT * FROM tab01;