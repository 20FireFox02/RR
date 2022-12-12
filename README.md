# Расчетная работа №1 
Вариант 4.16, способ выражения графа: спискок смежности. 

<b>Постановка задачи</b>: найти граф конденсации для орграфа

# Определения
- Граф — геометрический объект, состоящий из точек (вершин) и линий, которые их соединяют (рёбер).

- Простой цикл — это замкнутые обходы без повторного прохода по ребру или посещения вершины дважды, за исключением начальной и конечной вершин.

- Ориентированный граф или Орграф — граф, в котором рёбра имеют направления.

- Конденсация графа — представление исходного графа в виде конденсированного, в котором каждая вершина соответствует сильно связной компоненте исходного графа.

- Компонента связности — множество таких вершин графа, что между любыми двумя вершинами существует маршрут.

- Компонента сильной связности — максимальное множество вершин орграфа, между любыми двумя вершинами которого существует путь по дугам.

# Описание алгоритма
На вход из подается количество вершин графа(size) и сам граф в виде списка смежности(graf).
Программа использует алгоритм поиска в глубину(Depth-first search). 
Алгоритм поиска описывается рекурсивно: перебираем все исходящие из рассматриваемой вершины рёбра.
Общая идея алгоритма состоит в следующем: для каждой не пройденной вершины необходимо найти все не пройденные смежные вершины и повторить поиск для них. 
Код разбит на дополнительные функции choosetestfile(выбор запускаемого теста в консоли), readtestfile(чтение тестового файла), dfs.
