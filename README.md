# Расчетная работа №1 
Вариант 4.16, способ выражения графа: списки смежности. 

<b>Постановка задачи</b>: найти граф конденсации для орграфа

# Определения
- Граф - геометрический объект, состоящий из точек (вершин) и линий, которые их соединяют (рёбер).

- Простой цикл — это замкнутые обходы без повторного прохода по ребру или посещения вершины дважды, за исключением начальной и конечной вершин.

- Подграфом графа называется граф, являющийся подмоделью исходного графа. Иначе говоря, подграф содержит некоторые вершины исходного графа и некоторые рёбра (только те, оба конца которых входят в подграф).

- Граф, каждому ребру которого присвоено направление, называется ориентированным графом или орграфом.

- Связный граф — граф, содержащий ровно одну компоненту связности. Это означает, что между любой парой вершин этого графа существует как минимум один путь.

- Компонента сильной связности — максимальное множество вершин орграфа, между любыми двумя вершинами которого существует путь по дугам.

# Описание алгоритма
На вход из подается количество вершин графа(size) и сам граф в виде списка смежности(g).
Программа использует алгоритм поиска в глубину(Depth-first search). 
Алгоритм поиска описывается рекурсивно: перебираем все исходящие из рассматриваемой вершины рёбра.
Общая идея алгоритма состоит в следующем: для каждой не пройденной вершины необходимо найти все не пройденные смежные вершины и повторить поиск для них. 
Код разбит на дополнительные функции choosetestfile(выбор запускаемого теста в консоли), readtestfile(чтение тестового файла), dfs.
