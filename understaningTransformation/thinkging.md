1. keyboard activity detecting
we want to call the certain transformation function at certain place in renderscene(), so we should use the combination keyboard ~~attachments~~(capturing)
    glutKeyboard()
    glutSpecialFunc()

and also like this way:
at main() i don't know I should register all defined user capturing or call glutKeyboard() with needed capturing function in required place at function
...
I think I have the answer: we need call the glutKeyboard in those places when it required
2. the detailing for implementation step 
