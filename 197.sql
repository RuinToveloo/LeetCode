select t1.id as id
from Weather t1, Weather t2
where datediff(t1.recordDate, t2.recordDate) = 1 and t1.temperature > t2.temperature