CREATE TABLE Views (
    article_id INT not null,
    author_id INT not null,
    viewer_id INT not null,
    view_date DATE not null
);

INSERT INTO Views (article_id, author_id, viewer_id, view_date) VALUES
(1, 3, 5, '2019-08-01'),
(1, 3, 6, '2019-08-02'),
(2, 7, 7, '2019-08-01'),
(2, 7, 6, '2019-08-02'),
(4, 7, 1, '2019-07-22'),
(3, 4, 4, '2019-07-21'),
(3, 4, 4, '2019-07-21');




select distinct author_id as id
from Views
where author_id = viewer_id
order by author_id