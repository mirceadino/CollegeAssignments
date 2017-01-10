; Returns the maximum of depth from the children of the current root that
; contain an element E.
(defun max_children (L E)
  (cond
    ((null L) -1)
    (T (apply 'max -1 (mapcar (lambda (L) (depth L E)) (cdr L))))
    )
  )

; Returns the depth of of a node E in a tree represented as a list L or -1
; if the node doesn't exist.
(defun depth (L E)
  (cond
    ((null L) -1)
    ((equal (car L) E) 0)
    ((>= (max_children L E) 0) (+ 1 (max_children L E)))
    (T -1)
    )
  )

