CREATE DATABASE alkteszt1;

CREATE USER alkfelhasználó1@localhost IDENTIFIED BY 'H0ssz@bbJelsz0';

GRANT SELECT,INSERT,UPDATE,DELETE ON alkteszt1.* TO alkfelhasználó1@localhost;

USE alkteszt1;

CREATE TABLE tekézők
    (tekézőazonosító int primary key,
    név varchar(100),
    cím varchar(200),
    telefon varchar(20));

CREATE TABLE játszmák
    (játszmaazonosító int auto_increment primary key,
    tekézőazonosító int,
    pontszám int);

INSERT INTO tekézők VALUES
    (100, 'Ricsi', 'Böszörményi út 176.', '555-1234');

INSERT INTO tekézők VALUES
    (101, 'Barbara', 'Böszörményi út 176.', '555-5678');

INSERT INTO tekézők VALUES
    (102, 'Kati', 'Ibrány u. 2.', '555-0123');

INSERT INTO tekézők VALUES
    (103, 'Juci', 'Tisza Lajos körút 43.', '555-3256');

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (100, 110);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (100, 115);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (100, 105);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (101, 110);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (101, 112);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (101, 130);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (102, 115);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (102, 125);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (102, 140);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (103, 135);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (103, 138);

INSERT INTO játszmák (tekézőazonosító, pontszám) VALUES (103, 130);
