procedure TaskOne(n: integer);
begin
  var arr := ArrRandom(n:=n);
  Println(arr[::-1]);
end;

procedure TaskTwo(A: array of integer);
begin
  Println(A[::2]);
end;

procedure TaskThree(A: array of integer);
begin
  Println(Min(A[::2]));
end;

procedure TaskFour(A: array of integer);
begin
  var MaxIndex := A.IndexMax();
  Println(A[:MaxIndex] + A[MaxIndex+1:]);
end;

procedure TaskFive(A: array of integer; n: integer);
begin
  var MinIndex := A.IndexMin();
  Println(A[:MinIndex] + n + A[MinIndex:]);
end;

procedure TaskSix();
begin
  var seq := ArrRandom(20, -5, 20).Println();
  
  Println('L1: ', Lst(seq).FindAll(n -> n >= 0));
  Println('L2: ', Lst(seq).FindAll(n -> n < 0));
end;

procedure TaskSeven();
begin
  var L := Lst(ArrRandom(20));
  L.Println();
  L.RemoveAt(L.IndexMax());
  L.Println();
end;

begin
  Println('Задание 1');
  TaskOne(15);
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println();
  
  Println('Задание 2');
  TaskTwo(ArrRandom(15));
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
  
  Println('Задание 3');
  TaskThree(ArrRandom(15));
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
  
  Println('Задание 4');
  TaskFour(ArrRandom(15));
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
  
  Println('Задание 5');
  TaskFive(ArrRandom(15), ReadInteger('Введите число'));
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
  
  Println('Задание 7');
  TaskSeven();
  Println();
  Println('Нажмите Enter...');
  ReadLn;
  Println;
end.