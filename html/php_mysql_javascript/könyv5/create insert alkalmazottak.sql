CREATE TABLE alkalmazottak (
alkalmazottazonosító int primary key,
vezetéknév varchar(50),
keresztnév varchar(50),
részlegkód char(5),
kezdésdátuma date,
fizetés float);

INSERT INTO alkalmazottak VALUES
    (123, 'Nagy', 'Antal', 5, '2020-01-01', 250000);

INSERT INTO alkalmazottak (alkalmazottazonosító, vezetéknév, keresztnév)
    VALUES (124, 'Nagy', 'Barbara');