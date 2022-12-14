# Расчётная работа №1 
Вариант 4.16, способ выражения графа: спискок смежности. 

<b>Постановка задачи</b>: найти граф конденсации для орграфа

# Определения
- Граф — геометрический объект, состоящий из точек (вершин) и линий, которые их соединяют (рёбер).

- Простой цикл — это замкнутые обходы без повторного прохода по ребру или посещения вершины дважды, за исключением начальной и конечной вершин.

- Ориентированный граф или Орграф — граф, в котором рёбра имеют направления.

- Дуга — направленные рёбра в ориентированном графе.

- Транспонированный граф — исходный ориентированный граф с тем же набором вершин и с теми же дугами, но ориентация дуг этого графа противоположна ориентации дуг исходног графа.

- Компонента связности — множество таких вершин графа, что между любыми двумя вершинами существует маршрут.

- Компонента сильной связности — максимальное множество вершин орграфа, между любыми двумя вершинами которого существует путь по дугам.

- Конденсация графа — представление исходного графа в виде конденсированного, в котором каждая вершина соответствует сильно связной компоненте исходного графа.

# Описание алгоритма
Из файла берётся количество вершин графа(size) и сам граф в виде списка смежности(graf).
Программа использует алгоритм поиска в глубину(Depth-first search). 

Алгоритм поиска описывается рекурсивно: перебираем все исходящие из рассматриваемой вершины рёбра.

Общая идея алгоритма: исследуем все вершины графа по их времени выхода, после чего, используя время выхода из вершин, исследуем вершины транспонированного исходного графа.

Помимо основной, в коде присутствуют дополнительные функции: readfile — открытие файла и чтение из него графа; transposition — транспонирование исходного графа; dfs — поиск в глубину исходного графа; dfstr — поиск в глубину транспонированного графа; bypasscomp — поиск связи между компонентами.

<h2> Алгоритм</h2>

1. Создаётся ещё один граф путём транспонирования исходного.

2. Выбираем любую непройденую вершину. Если таковой нет, то преходим к пункту 6.

3. Помечаем вершину как пройденную.

4. Переходим к следующей непройденой вершине, с которой она связана, и переходим к пункту 3; иначе заносим вершину в вектор пройденных вершин по времени выхода из неё.

5. Откатываемся к предыдущей вершине (если такая существует) и переходим к пункту 4, иначе переходим к пункту 2.

6. Для дальнейших шагов используем транспонированный граф как показатель связей вершин.

7. Осматриваем вектор пройденных вершин от последней пройденной вершины.

8. Берём последнюю неисследованную вершину. Если таковой нет, то переходим к пункту 15.

9. Заносим вершину в компоненту и помечаем её как исследованную.

10. Переходим к следующей неисследованной вершине, с которой она связана, и переходим к пункту 9; иначе переходим к пункту 11.

11. Откатываемся к предыдущей вершине (если такая существует) и переходим к пункту 10, иначе переходим к пункту 12.

12. Заносим полученную компоненту в граф компонент.

13. Очищаем компоненту.

14. Переходим к пункту 8.

15. Для дальнейших шагов используем исходный граф как показатель связей вершин.

16. Берём любую непройденую компоненту. Если таковых нет, то завершаем программу.

17. Берём любую непройденую вершину данной компоненты. Если таковых нет, то переходим к пункту 16.

18. Берём любу непройденую вершину любой другой компоненты. Если все другие компоненты пройдены, то переходим к пункту 17.

19. Если исходная вершина связана с исследуемой, то исходная компонента связана с исследуемой компонентой — заносим данную связь в граф конденсации.

20. Переходим к пункту 18.

В итоге получается конденсированный граф, представленный в виде списка смежности.

# Примеры выполнения

<h3>Граф №1:</h3>

![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/1source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/1output.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/45c8225a5b5f89917c8cdbc52b8b40b9354e4315/1compliting.png)


<h3>Граф №2:</h3>

![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/2source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/2output.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/2compliting.png)


<h3>Граф №3:</h3>

![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/3source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/3output.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/3compliting.png)


<h3>Граф №4:</h3>

![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/4source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/4output.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/4compliting.png)


<h3>Граф №5:</h3>

![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/5source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/5output.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/5compliting.png)


<h3>Граф №6:</h3>

![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/6source.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/6output.png)
![1testpict2 0](https://github.com/20FireFox02/RR/blob/16c62e13bbbd8d83c771ab50996e6175d8ff57f1/6compliting.png)

# Вывод
По ходу данной расчётной работы я ознакомился с теорией графов, где более подробно узнал об ориентированных графах, компонентах сильной связности, графах конденсации; изучил работу поиска в глубину и методы решения задач с графами в языке С++; научился использовать в работе новые библиотеки С++: vector, string, fstream.

# Источники
https://habr.com/ru/company/otus/blog/568026/

https://habr.com/ru/company/otus/blog/675730/

https://habr.com/ru/post/570612/

https://e-maxx.ru/algo/strong_connected_components
