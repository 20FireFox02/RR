# Расчетная работа №1 
Вариант 4.16, способ выражения графа: спискок смежности. 

<b>Постановка задачи</b>: найти граф конденсации для орграфа

# Определения
- Граф — геометрический объект, состоящий из точек (вершин) и линий, которые их соединяют (рёбер).

- Простой цикл — это замкнутые обходы без повторного прохода по ребру или посещения вершины дважды, за исключением начальной и конечной вершин.

- Ориентированный граф или Орграф — граф, в котором рёбра имеют направления.

- Транспонированный граф — исходный ориентированный граф с тем же набором вершин и с теми же дугами, но ориентация дуг этого графа противоположна ориентации дуг исходног графа.

- Конденсация графа — представление исходного графа в виде конденсированного, в котором каждая вершина соответствует сильно связной компоненте исходного графа.

- Компонента связности — множество таких вершин графа, что между любыми двумя вершинами существует маршрут.

- Компонента сильной связности — максимальное множество вершин орграфа, между любыми двумя вершинами которого существует путь по дугам.

# Описание алгоритма
На вход из подается количество вершин графа(size) и сам граф в виде списка смежности(graf).
Программа использует алгоритм поиска в глубину(Depth-first search). 
Алгоритм поиска описывается рекурсивно: перебираем все исходящие из рассматриваемой вершины рёбра.
Общая идея алгоритма состоит в следующем: для каждой не пройденной вершины необходимо найти все не пройденные смежные вершины и повторить поиск для них. 
Код разбит на дополнительные функции choosetestfile(выбор запускаемого теста в консоли), readtestfile(чтение тестового файла), dfs.
# Алгорим
1. Создаётся ещё один граф путём транспонирования исходного.
2. Выбираем любую непройденую вершину.
3. Заносим вершину в вектор пройденных вершин по времени входа в неё и помечаем её как пройденую.
4. Переходим к следуюющей не пройденой вершине, с которой она связана.
5. Когда по данной ветке не осталось непомеченных вершин, то переходим к пункту 6.
6. Когда все вершины помечены как пройденные, то заканчиваем цикл, иначе переходим к пункту 2.
7. Для дальнейших шагов используем транспонированный граф как показатель связей вершин.
8. Осматриваем вектор пройденных вершин от последней пройденной верщин.
9. Берём последнюю неисследованную вершину.
10. Заносим вершину в компоненту и помечаем её как исследованную.
11. Переходим к следуюющей неисследованной вершине, с которой она связана.
12. Когда по данной ветке не осталось неисследованных вершин, то переходим к пункту 13.
13. Заносим полученную компоненту в граф компонент.
14. Очищаем компоненту.
15. Когда все вершины помечены как исследованные, то заканчиваем цикл, иначе переходим к пункту 9.
16. Для дальнейших шагов используем исходный граф как показатель связей вершин.
17. Берём любую не пройденую компоненту.
18. Берём любую не пройденую вершину данной компоненты.
19. Берём любу непройденую вершину любой другой компоненты.
20. Если исходная вершина связана с исследуемой, то исходная компонента связана с исследуемой компонентой.

# Примеры выполнения

Граф №1:
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/1source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/1output.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/45c8225a5b5f89917c8cdbc52b8b40b9354e4315/1compliting.png)


Граф №2:
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/2source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/2compliting.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/2output.png)

Граф №3:
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/3source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/3compliting.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/3output.png)

Граф №4:
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/4source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/4compliting.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/4output.png)

Граф №5:
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/5source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/5compliting.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/5output.png)

Граф №6:
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/6source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/6compliting.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/6output.png)

# Источники
https://habr.com/ru/company/otus/blog/568026/

https://habr.com/ru/company/otus/blog/675730/

https://e-maxx.ru/algo/strong_connected_components

https://ru.wikipedia.org/wiki/Транспонированный_граф
