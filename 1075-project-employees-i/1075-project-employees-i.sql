# Write your MySQL query statement below
# Write your MySQL query statement below
select P.project_id, round(avg(E.experience_years), 2) as average_years from Project P left join Employee E on E.employee_id = P.employee_id group by P.project_id;