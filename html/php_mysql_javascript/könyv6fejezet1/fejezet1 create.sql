CREATE DATABASE árverés;

CREATE USER 'ás_felhasználó'@'localhost'
    IDENTIFIED BY 'ÁrverésSegéd';

GRANT SELECT,UPDATE,INSERT,DELETE
    ON árverés.* TO 'ás_felhasználó'@'localhost';
	
USE árverés;

CREATE TABLE ajánlattevők (
    ajánlattevőazonosító int primary key,
    vezetéknév varchar(100),
    keresztnév varchar(100),
    cím varchar(200),
    telefon varchar(14));

CREATE TABLE tételek (
    tételazonosító int primary key,
    név varchar(100),
    leírás text,
    viszonteladóiár decimal(10),
    nyertesajánlattevő int,
    nyertesár decimal(10));

CREATE TABLE rendszergazdák (
    felhasználóiazonosító varchar(20) primary key,
    név varchar(100),
    jelszó char(64));

INSERT INTO rendszergazdák
    VALUES ('ricsi', 'Nagy Ricsi', SHA2('H0ssz@bbJelsz0',256));