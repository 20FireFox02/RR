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
1. Создаётся ещё один граф путём транспонирования исходного.

2. Выбираем любую непройденую вершину, обозначив её как v.

2.1 Заносим вершину в вектор пройденных вершин по времени входа в неё и помечаем её как пройденую.

2.2 Проверяем вершин на связь с другой любой связанной с ней вершиной.

2.3 Если данная вершина не помечена как пройденная — присваем ей значение v, переходим к пункту 

2.1.Когда все вершины помечены как пройденные, то заканчиваем цикл.

Для дальнейших шагов используем транспонированный граф как показатель связей вершин.

Осматриваем вектор пройденных вершин от последней пройденной верщины.

Заносим вершину в компоненту и помечаем её как пройденую.

Проверяем вершин на связь с другой любой связанной с ней вершиной.

Если данная вершина не помечена как пройденная — присваем ей значение v, переходим к пункту

Очтщаем компоненту

Для дальнейших шагов используем исходный граф как показатель связей вершин.

Берём любую компоненту.

Берём любую верщину данной компоненты.

Комонента с вершиной, которая связанна с исходной и не принадлежащая к исходной компоненте, будет связана с исходной компонентой.

![1testpict2 0](https://github.com/20FireFox02/RR/blob/45c8225a5b5f89917c8cdbc52b8b40b9354e4315/1compliting.png)
