procedure TaskOne();
begin
  var i: integer;
  var iPtr: ^integer;
  
  i := 2;
  iPtr := @i;
  
  Println(iPtr^);
end;







type
  Node = record
    wrd: string;
    count: integer;
    next: ^Node;
  end;

function CreateNode(NewWord: string): ^Node;
var
  NewNode: ^Node;
begin
  New(NewNode);
  
  NewNode^.wrd := NewWord;
  NewNode^.count := 1;
  NewNode^.next := nil;
  Result := NewNode;
end;

procedure AddFirst(var Head: ^Node; NewNode: ^Node);
begin
  NewNode^.next := Head;
  Head := NewNode;
end;

procedure AddAfter(NewNode: ^Node; p: ^Node);
begin
  NewNode^.next := p^.next;
  p^.next := NewNode;
end;

procedure AddBefore(var Head: ^Node; p, NewNode: ^Node);
var pp: ^Node;
begin
  pp := Head;
  if p = Head then
    AddFirst(Head, NewNode)
  else
  begin
    while (pp <> nil) and (pp^.next <> p) do
      pp := pp^.next;
    if pp <> nil then AddAfter(pp, NewNode);
  end;
end;

procedure AddLast(var Head: ^Node; NewNode: ^Node);
begin
  var pp: ^Node;
  
  if Head = nil then
    AddFirst(Head, NewNode)
  else
  begin
    pp := Head;
    while pp^.next <> nil do
      pp := pp^.next;
    AddAfter(pp, NewNode);
  end;
end;

function Find(Head: ^Node; NewWord: string): ^Node;
var pp: ^Node;
begin
  pp := Head;
  while (pp <> nil) and (NewWord <> pp^.wrd) do 
    pp := pp^.next;
  Result := pp;
end;

function FindPlace(Head: ^Node; NewWord: string): PNode;
var pp: ^Node;
begin
  pp := Head;
  while (pp <> nil) and (NewWord <> pp^.wrd) do
    pp := pp^.next;
  Result := pp;
end;

function TakeWord (F: Text): string;
var c: char;
begin
  Result := '';
  c := ' ';
  while not eof(f) and (c <= ' ') do
    read(F, c);
  while not eof(f) and (c > ' ') do
  begin
    Result += c;
    read(F, c);
  end;
end;

procedure TaskTwo();
begin
  var f: Text;
  Assign(f, 'text.txt');
  Reset(f);
  
  while TakeWord(f) <> '' do
  begin
    
  end;
end;

begin
  TaskOne();
end.