create table Tweets (
    tweet_id int not null,
    content varchar(255) not null
);

insert into Tweets (tweet_id, content) VALUES
(1, 'Let us Code '),
(2, 'More than fifteen chars are here! ');


select tweet_id as tweet_id
from Tweets
where length(content) > 15