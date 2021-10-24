#pragma once
int RemoveClause(pcnf L, int flag) {  //一次找出一个变元，并删除
  pcNode p;
  plNode q;
  p = L->firstc;
  while (p) {
    if (p->mark == 0) {
    p = p->next;
    continue;
    }
    else {
      q = p->firstl;
      while (q) {
        if (q->mark == 0) {
          q = q->next;
          continue;
        }   
        else {
          if (q->l == flag) {  //子句中有flag，删除子句
            p->mark = 0;
            p->flag = flag;
            L->claunum--;  //子句数目减一
            break;
          } else if (q->l == -flag) {  //子句中有-flag，删除该文字
            q->mark = 0;
            p->l_count--;  //文字数目减一
            break;
          } else
            q = q->next;
        }
      }
      p = p->next;
    }
  }
  L->varinum--;  //删除变元后，变元数目减一
  return OK;
}

int AddClause(pcnf L, int flag) {  //恢复前面因为flag而删除的元素，子句
  pcNode p;
  plNode q;
  p = L->firstc;
  while (p) {
    q = p->firstl;
    if (p->mark == 1) { 
        //恢复非L规则删除的文字
q = p->firstl;
      while (q) {
        if (q->mark == 0 && q->l == -flag) {
          q->mark = 1;
          p->l_count++;  //子句文字数目加一
          break;
        } else
          q = q->next;
      }
    } else if (p->mark == 0 && p->flag == flag) {  //恢复子句
      p->mark = 1;
      p->flag = 0;
      L->claunum++;
    } else {
      while (q) {
        if (q->mark == 0 && q->l == -flag) {
          q->mark = 1;
          p->l_count++;  //子句文字数目加一
          break;
        } else
          q = q->next;
      }
    }
    p = p->next;
  }
  L->varinum++;  //变元数目加一
  return OK;
}

int EmptyClause(pcnf L) {  //查看是否有空句
  pcNode p = L->firstc;
  while (p) {
    if (p->l_count == 0 && p->mark == 1)
      return OK;  //当文字数为0，且子句未经过删减，则是空句
    p = p->next;
  }
  return FALSE;
}
void tauto(pcnf L) {
  pcNode p = L->firstc;
  plNode q, qn;
  while (p) {
    q = p->firstl;
    while (q) {
      qn = q->next;
      while (qn!=NULL) {
        if (qn->l == -q->l) {
          p->mark = 0;
          p->flag = 0;
          L->claunum--;
          break;
        }
        qn = qn->next;
      }
      if (p->mark == 0)
        break;
      q = q->next;
    }
    p = p->next;
  }
}
int single(pcnf L) {
  pcNode p;
  p = L->firstc;
  while(p) {
  if(p->l_count==1&&p->mark==1 ) {
      plNode q;
    q = p->firstl;
      while (q) {
      if (q->mark == 1)
        return q->l;
      else {
        q = q->next;
      }
      }
  }
  p = p->next;
  }
  return FALSE;
}

int DPLL(pcnf L, SqList& An) {
  if (L->claunum == 0)
    return TRUE;
  if (EmptyClause(L)==OK)
    return FALSE;
  int tar =single(L);
  int b = Bn.length;
  int m;
  while (tar) {
    Bn.elem[Bn.length++] = tar;
    RemoveClause(L, tar);
    if (L->claunum == 0) {
    for(int i=0;i<Bn.length;i++){
        int temp = Bn.elem[i];
      if (temp > 0)
        An.elem[temp] = 1;
      else
        An.elem[-temp] = -1;
    }
    Bn.length = 0;
    return OK;
    } else if (EmptyClause(L)==OK) {
      for (int i = Bn.length- 1; i >= b; i--)
        AddClause(L, Bn.elem[i]);
      Bn.length = b;
      return FALSE;
    }
    tar = single(L);
    }
    if (choose == 1) {
    tar = option1(&m);
    } 
    else if (choose == 2) {
      tar = option2(L);
    }
    RemoveClause(L, tar);
    if (DPLL(L, An)==OK) {
      if (tar > 0)
        An.elem[tar] = 1;
      else {
        An.elem[-tar] = -1;
      }
      for(int i=0;i<Bn.length;i++) {
        int temp = Bn.elem[i];
        if (temp > 0)
          An.elem[temp] = 1;
        else
          An.elem[-temp] = -1;

      }
      Bn.length = 0;
      return OK;
    }
    tar = -tar;
    reverse(L, tar);
    if (DPLL(L, An)) {
      if (tar > 0)
        An.elem[tar] = 1;
      else {
        An.elem[-tar] = -1;
      }
      for (int i = 0; i < Bn.length; i++) {
        int temp = Bn.elem[i];
        if (temp > 0)
          An.elem[temp] = 1;
        else
          An.elem[-temp] = -1;
      }
      Bn.length
      = 0;
      return OK;
    }
    AddClause(L, tar);
    if (choose == 1)
      value[m] = 1;
    for (int i = Bn.length - 1; i >=b;i--)
      AddClause(L, Bn.elem[i]);
    Bn.length = b;
    return FALSE;
  }

int reverse(pcnf L, int flag) {
  pcNode p = L->firstc;
  while (p) {
    if (p->flag == -flag) {
      p->flag = 0;
      p->mark = 1;
      p->l_count--;
      plNode q = p->firstl;
      while (q->l != -flag)
        q = q->next;
      q->mark = 0;
      L->claunum++;
    } else if (p->mark == 1) {
      plNode q = p->firstl;
      while (q) {
        if (q->l == flag) {
          p->flag = flag;
          p->mark = 0;
          q->mark = 1;
          p->l_count++;
          L->claunum--;
          break;
        }
        q = q->next;
      }
    }
    p = p->next;
  }
  return OK;
}
int option1(int *m) {
  int i = 0;
  while (1) {
    if (value[i]) {
      int j = 0;
      for (; j < Bn.length; j++) {
        if (key[i] == abs(Bn.elem[j]))
          break;
      }
      if (j == Bn.length) {
        *m = i;
        value[i] = 0;
        return key[i];
      }
    }
    i++;
  }
}
int option2(pcnf L) {
  int i;
  pcNode p;
  plNode q;
  for(i=2;i;i++) {
    p = L->firstc;
    while (p) {
      if (p->l_count == i && p->mark == 1) {
        q = p->firstl;
        while (q) {
          if (q->mark == 1)
            return q->l;
          q = q->next;
        }
      }
      p = p->next;
    }
  }
}