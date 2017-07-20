# SKV Syntax
## Description

Simple Key Value Syntax allows to store easily variables into a file.
No need to use or to know XML or YAML !

## How to use
To write a variable you need to use the next syntax:
```
foo:hello_world
```

SKV will see that the key **foo** have the value **hello_world**.

### Warning 

Each key/value couples much be separated by a line break (\n)!

Do not do this:
```
foo:hello fooBis:world
```
It will only recognizes the key **foo** having the value **hello fooBis:world**...

To get both **foo** and **fooBis** do this:
```
foo:hello
fooBis:world
```

Also, do no put extra whitespaces between the separator, SKV keeps ALL the whitespaces :
```
foo : hello
```
Or the key **"foo "** will get the value **" hello"**

### Advise 
Keep it really simple ! 