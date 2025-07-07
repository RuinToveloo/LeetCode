
create table EmployeeUNI (
    id INT not null,
    unique_id INT not null
);

create table Employees (
    id INT not null,
    name varchar(255) not null
);

insert into Employees(id, name) VALUES
(1, 'Alice'),
(7, 'Bob'),
(11, 'Meir'),
(90, 'Winston'),
(3, 'Jonathan');

insert into EmployeeUNI(id, unique_id) VALUES
(3, 1),
(11, 2),
(90, 3);



select t2.unique_id as unique_id, t1.name as name
from Employees t1
left join EmployeeUNI t2
on t1.id = t2.id;