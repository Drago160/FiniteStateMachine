# FiniteStateMachine

## Для сборки проекта достаточно в корне:
mkdir build  
cd build  
cmake ..  
make  
Для запуска тестов можно перейти в src/bin и исполнить бинарник  
Бинарник для запуска основной программы лежать будет в build  

Если вы хотите запустить через Clion, можно открыть как проект и запустить либо run для программы либо BasicFsmTests - это запустит все тесты  


## Формат входных данных в файл для NFSM:
#вершин #ребер  
маска терминальных вершин (например 1 0 0 0 1 0 0) - означает, что терминальные: 0, 4)
Переходы в формате:  
src letter path - тут из src ведет стрелка в path по букве letter
При этом letter = 1 - означает, что переходы по eps.
### Пример:
4 4  
0 0 0 1  
0 1 1  
1 1 2  
2 a 3  
3 a 3  
Задает автомат:
<?xml version="1.0" standalone="no"?>
<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "https://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">

<svg width="800" height="150" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="59.5" cy="61.5" rx="30" ry="30"/>
	<text x="54.5" y="67.5" font-family="Times New Roman" font-size="20">0</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="266.5" cy="61.5" rx="30" ry="30"/>
	<text x="261.5" y="67.5" font-family="Times New Roman" font-size="20">1</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="485.5" cy="61.5" rx="30" ry="30"/>
	<text x="480.5" y="67.5" font-family="Times New Roman" font-size="20">2</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="708.5" cy="61.5" rx="30" ry="30"/>
	<text x="703.5" y="67.5" font-family="Times New Roman" font-size="20">3</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="708.5" cy="61.5" rx="24" ry="24"/>
	<polygon stroke="black" stroke-width="1" points="89.5,61.5 236.5,61.5"/>
	<polygon fill="black" stroke-width="1" points="236.5,61.5 228.5,56.5 228.5,66.5"/>
	<text x="158.5" y="82.5" font-family="Times New Roman" font-size="20">&#949;</text>
	<polygon stroke="black" stroke-width="1" points="515.5,61.5 678.5,61.5"/>
	<polygon fill="black" stroke-width="1" points="678.5,61.5 670.5,56.5 670.5,66.5"/>
	<text x="592.5" y="82.5" font-family="Times New Roman" font-size="20">a</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 737.516,68.645 A 22.5,22.5 0 1 1 720.479,88.877"/>
	<text x="765.5" y="125.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon fill="black" stroke-width="1" points="720.479,88.877 717.547,97.844 727.254,95.442"/>
	<polygon stroke="black" stroke-width="1" points="296.5,61.5 455.5,61.5"/>
	<polygon fill="black" stroke-width="1" points="455.5,61.5 447.5,56.5 447.5,66.5"/>
	<text x="371.5" y="82.5" font-family="Times New Roman" font-size="20">&#949;</text>
</svg>

## Формат входных данных в файл для DFSM: 
#вершин(n)  
маска терминальных вершин  
x0 y0  
x1 y1  
.....  
xn yn  
где xi, yi - вершины куда есть переход из i по a, b соответственно  

### Пример:
5  
0 1 1 1 0  
1 4  
2 4  
3 4  
3 4  
4 4  
Задает автомат:  
<?xml version="1.0" standalone="no"?>
<svg width="800" height="400" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="84.5" cy="307.5" rx="30" ry="30"/>
	<text x="79.5" y="313.5" font-family="Times New Roman" font-size="20">0</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="84.5" cy="72.5" rx="30" ry="30"/>
	<text x="79.5" y="78.5" font-family="Times New Roman" font-size="20">1</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="84.5" cy="72.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="354.5" cy="72.5" rx="30" ry="30"/>
	<text x="349.5" y="78.5" font-family="Times New Roman" font-size="20">2</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="354.5" cy="72.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="635.5" cy="72.5" rx="30" ry="30"/>
	<text x="630.5" y="78.5" font-family="Times New Roman" font-size="20">3</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="635.5" cy="72.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="354.5" cy="307.5" rx="30" ry="30"/>
	<text x="349.5" y="313.5" font-family="Times New Roman" font-size="20">4</text>
	<polygon stroke="black" stroke-width="1" points="84.5,277.5 84.5,102.5"/>
	<polygon fill="black" stroke-width="1" points="84.5,102.5 79.5,110.5 89.5,110.5"/>
	<text x="70.5" y="196.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon stroke="black" stroke-width="1" points="114.5,307.5 324.5,307.5"/>
	<polygon fill="black" stroke-width="1" points="324.5,307.5 316.5,302.5 316.5,312.5"/>
	<text x="214.5" y="328.5" font-family="Times New Roman" font-size="20">b</text>
	<polygon stroke="black" stroke-width="1" points="114.5,72.5 324.5,72.5"/>
	<polygon fill="black" stroke-width="1" points="324.5,72.5 316.5,67.5 316.5,77.5"/>
	<text x="215.5" y="63.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon stroke="black" stroke-width="1" points="107.129,92.196 331.871,287.804"/>
	<polygon fill="black" stroke-width="1" points="331.871,287.804 329.119,278.781 322.554,286.324"/>
	<text x="204.5" y="210.5" font-family="Times New Roman" font-size="20">b</text>
	<polygon stroke="black" stroke-width="1" points="384.5,72.5 605.5,72.5"/>
	<polygon fill="black" stroke-width="1" points="605.5,72.5 597.5,67.5 597.5,77.5"/>
	<text x="490.5" y="93.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon stroke="black" stroke-width="1" points="354.5,102.5 354.5,277.5"/>
	<polygon fill="black" stroke-width="1" points="354.5,277.5 359.5,269.5 349.5,269.5"/>
	<text x="339.5" y="196.5" font-family="Times New Roman" font-size="20">b</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 664.637,79.134 A 22.5,22.5 0 1 1 647.958,99.662"/>
	<text x="693.5" y="135.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon fill="black" stroke-width="1" points="647.958,99.662 645.184,108.679 654.848,106.107"/>
	<polygon stroke="black" stroke-width="1" points="612.487,91.746 377.513,288.254"/>
	<polygon fill="black" stroke-width="1" points="377.513,288.254 386.857,286.958 380.442,279.287"/>
	<text x="479.5" y="181.5" font-family="Times New Roman" font-size="20">b</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 358.573,337.104 A 22.5,22.5 0 1 1 333.48,328.74"/>
	<text x="301.5" y="393.5" font-family="Times New Roman" font-size="20">a, b</text>
	<polygon fill="black" stroke-width="1" points="333.48,328.74 324.064,329.326 329.88,337.46"/>
</svg>

##### MDFSM задается аналогично DFSM, но тогда нужно гарантировать то что для данного языка он введен верно
3  
0 1 0  
1 2  
1 2  
2 2  
Задает автомат:  
<?xml version="1.0" standalone="no"?>
<svg width="800" height="350" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="179.5" cy="64.5" rx="30" ry="30"/>
	<text x="174.5" y="70.5" font-family="Times New Roman" font-size="20">0</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="487.5" cy="64.5" rx="30" ry="30"/>
	<text x="482.5" y="70.5" font-family="Times New Roman" font-size="20">1</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="487.5" cy="64.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="323.5" cy="210.5" rx="30" ry="30"/>
	<text x="318.5" y="216.5" font-family="Times New Roman" font-size="20">2</text>
	<polygon stroke="black" stroke-width="1" points="209.5,64.5 457.5,64.5"/>
	<polygon fill="black" stroke-width="1" points="457.5,64.5 449.5,59.5 449.5,69.5"/>
	<text x="329.5" y="85.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon stroke="black" stroke-width="1" points="200.566,85.859 302.434,189.141"/>
	<polygon fill="black" stroke-width="1" points="302.434,189.141 300.376,179.934 293.256,186.956"/>
	<text x="236.5" y="158.5" font-family="Times New Roman" font-size="20">b</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 517.055,60.088 A 22.5,22.5 0 1 1 508.98,85.275"/>
	<text x="559.5" y="97.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon fill="black" stroke-width="1" points="508.98,85.275 509.674,94.683 517.741,88.774"/>
	<polygon stroke="black" stroke-width="1" points="465.093,84.448 345.907,190.552"/>
	<polygon fill="black" stroke-width="1" points="345.907,190.552 355.207,188.967 348.558,181.498"/>
	<text x="410.5" y="158.5" font-family="Times New Roman" font-size="20">b</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 336.725,237.297 A 22.5,22.5 0 1 1 310.275,237.297"/>
	<text x="309.5" y="299.5" font-family="Times New Roman" font-size="20">a, b</text>
	<polygon fill="black" stroke-width="1" points="310.275,237.297 301.527,240.83 309.618,246.708"/>
</svg>

# Краткое описание необходимых методов:
### NFSM:
- NFSM(filename) - делает из данного файла NFSM
- FilchEps() - стягивает eps-переходы
- bool RecognizeWord(word) - возвращает результат принадлежания word языку этого автомата
### DFSM:
- DFSM(NFSM) - конструктор из NFSM
- DFSM(filename) - конструктор из файла, при этом будьте внимательны входной автомат должен быть ПДКА
- bool RecognizeWord(word) - ...
### MDFSM
- MDFSM(DFSM) - делает из DFSM минимизируя его
- RecoginzeWord(word) - ...
- Complement() - преобразуется в дополнение
### RegularFSM
Этот класс отвечает за построение регулярки - на самом деле это не автомат)))
- Regular_automat(DFSM) - конструктор из DFSM
- MakeRegular() - преобразует себя в подобающий для дальнейшего вид - рекомендуется исполнятт всякий раз после создания
- PrintRegex() - выводит регулярку в командную строку
- PrintForLatex() - выводит ту же регулярку чтоб закинуть ее в Latex

При этом в дирректории tests/SM_examples вы можете посмотреть некоторые автоматыи как их вводить, в частности:
## Для NFSM:
|Q| |delta|
Маски для состояний(1 - завершающее, 0 - нет)  
переходы (q1, v) -> q2 в формате q1_v_q2  
## Для MDFSM
- |Q|  
Маски для состояний(1 - завершающее, 0 - нет)  
i_j   
где i, j - это переходы из данной вешины(по номеру запроса) в буквы a и b  


При этом можно обобщить на больший алфавит но те же входные данные мои не пойдут но можно прееделать очевидным образом и изменить глобальную константу

### Регулярка для моих тестовых автоматов:
1. a+
2. (a+b)
3. (1 + (a+b)*b)b(a+b)*
4. (ab+ba)*(1 + a + ba)
5. (aa)*b + ((a+b)^2)*  

Они все из наших дз к слову