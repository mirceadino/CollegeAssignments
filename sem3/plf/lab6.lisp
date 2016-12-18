(defun split (L V E)
  (cond
    (
     (null L)
     (list NIL NIL)
     )
    (
     (equal v (+ e 1))
     (list NIL L)
     )
    (t
      (list
        (append
          (list (car L))
          (list (cadr L))
          (car (split (cddr L) (+ v 1) (+ e (cadr L))))
          )
        (cadr (split (cddr L) (+ v 1) (+ e (cadr L))))
        )
      )
    )
  )

(defun lefttree (L)
  (car (split (cddr L) 0 0))
  )

(defun righttree (L)
  (cadr (split (cddr L) 0 0))
  )

(defun root (L)
  (car L)
  )

(defun postorder (L)
  (cond
    ((null L) ())
    (t
      (append
        (postorder (lefttree L))
        (postorder (righttree L))
        (list (root L))
        )
      )
    )
  )
