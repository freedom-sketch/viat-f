procedure TaskOne(A: array of integer);
begin
  var arr := ArrRandom(n:=10);
  Println(A[::-1]);
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
  TaskSeven();
end.