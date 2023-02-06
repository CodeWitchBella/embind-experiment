# embind test playground

Important findings:

- .clone() creates a reference (not a copy as its name might suggest)
- .property creates a copy (not a reference as you might expect)
- both of them need to be .delete()-ed
