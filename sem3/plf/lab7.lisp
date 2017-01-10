(defun check (L E)
  (cond
    ((and (atom L) (equal L E)) 1)
    ((and (atom L) (not (equal L E))) 0)
    (T (apply 'max (mapcar (lambda (L) (check L E)) L)))
    )
  )

(defun main (L E)
  (cond
    ((equal (check L E) 0) NIL)
    (T T)
    )
  )

