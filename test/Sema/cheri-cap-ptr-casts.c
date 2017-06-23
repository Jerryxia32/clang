// RUN: %clang_cc1 %s -triple cheri-unknown-freebsd -fsyntax-only -ast-dump | FileCheck %s
void f() {
  __capability char *x;
  // CHECK: CStyleCastExpr {{.*}} {{.*}} 'char *' <CheriCapabilityToPointer>
  char *y = (char *)x;
}

void g() {
  char *x;
  // CHECK: CStyleCastExpr {{.*}} {{.*}} 'char * __capability' <PointerToCheriCapability>
  __capability char *y = (__capability char *)x;
}
