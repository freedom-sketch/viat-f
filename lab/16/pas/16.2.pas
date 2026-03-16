uses Tools;

procedure TaskOne();
begin
  var Birth := new DateTime(2008, 5, 21);
  var Student := new Anketa('Боков М. А.', Birth, 2);
  
  var BirthDateStr := Student.birth.ToString('dd.MM.yyyy');
  
  Println($'ФИО: {Student.fio}{#10}День рождения: {BirthDateStr}{#10}Курс: {Student.kurs}');
end;

procedure TaskTwo();
begin
  var table := new Anketa[5];
  
  WritelnFormat('{0,-20} {1,-15} {2,5}', 'ФИО', 'Дата рождения', 'Курс');
  for var i := 0 to length(Table) - 1 do
  begin
    var Raw := new Anketa(true);
    table[i] := Raw;
    
    var BirthDateStr := Raw.BirthStr;
    WritelnFormat('{0,-20} {1,-15} {2,3}', Raw.fio, BirthDateStr, Raw.kurs);
  end;
end;

///Создать запись toy с информацией об
///имеющихся в продаже игрушках (название товара (name),
///цена товара (price) и возрастной диапазон (age), для которого
///игрушка предназначена). Заполнить несколько товаров.
///Вывести данные на экран. Использовать массив и конструкцию with.
procedure TaskThree();
begin
  var Table := new Toy[3];
  
  for var i := 0 to length(Table) - 1 do
    with Table[i] do
    begin
      Name := Chr(Random(1040, 1072)) + Chr(Random(1072, 1104));;
      Price := Random(100, 2000);
      
      var MnAg := Random(0, 6);
      MinAge := MnAg;
      MaxAge := Random(MnAg, 18);
    end;
  
  WritelnFormat('{0,-20} {1,-15} {2,5}', 'Название', 'Цена', 'Возраст');
  for var i := 0 to length(Table) - 1 do
  begin
    var Raw := Table[i];
    var AgeRange := Raw.AgeRange;
    WritelnFormat('{0,-20} {1,-15} {2,3}', Raw.Name, Raw.Price, AgeRange);
  end;
end;

//procedure TaskFour();
//begin
//  var FileName := 'toys.dat';
//  var n := 3;
//  var ToysOriginal := new Toy[n];
//  
//  for var i := 0 to n - 1 do
//    with ToysOriginal[i] do
//    begin
//      Name := Chr(Random(1040, 1072)) + Chr(Random(1072, 1104));
//      Price := Random(100, 2000);
//      
//      var MnAg := Random(0, 6);
//      MinAge := MnAg;
//      MaxAge := Random(MnAg, 18);
//    end;
//  
//  var f: file of Toy;
//  Assign(f, FileName);
//  Rewrite(f);
//  for var i := 0 to n - 1 do
//    write(f, ToysOriginal[i]);
//  Close(f);
//
// var ToysRead := new Toy[n];
//  Reset(f);
//  for var i := 0 to n - 1 do
//    read(f, ToysRead[i]);
//  Close(f);
//  
//  WritelnFormat('{0,-20} {1,-15} {2,5}', 'Название', 'Цена', 'Возраст');
//  for var i := 0 to n - 1 do
//  begin
//    var Raw := ToysRead[i];
//    var AgeRange := Raw.AgeRange;
//    WritelnFormat('{0,-20} {1,-15} {2,3}', Raw.Name, Raw.Price, AgeRange);
//  end;
//end;

procedure TaskFive();
begin
  var n := ReadInteger('Введите количество лет: ');
  
  if (n mod 100) in 11..14 then
    Println(n, ' лет')
  else
    case n mod 10 of
      1: Println(n, ' год');
      2, 3, 4: Println(n, ' года');
    else
      Println(n, 'лет');
    end;
end;

procedure TaskSix();
type
  t_chs = set of Char;

const
  lett: t_chs = ['a'..'z', 'A'..'Z', '_'];
  num: t_chs = ['0'..'9'];

begin
  var str := ReadString('Введите строку для проверки: ');
  
  var flag := True;
  
  if not (str[1] in lett) then
    flag := False
  else
  begin
    for var i := 2 to Length(str) do
    begin
      if not (str[i] in lett + num) then
      begin
        flag := False;
        break;
      end;
    end;
  end;
  
  if flag then
    WriteLn('Строка корректна')
  else
    WriteLn('Строка содержит недопустимые символы');
end;

begin
  Println('Задание 1');
  TaskOne();
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
  
  Println('Задание 2');
  TaskTwo();
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
  
  Println('Задание 3');
  TaskThree();
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
  
  Println('Задание 5');
  TaskFive();
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
  
  Println('Задание 6');
  TaskSix();
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
end.