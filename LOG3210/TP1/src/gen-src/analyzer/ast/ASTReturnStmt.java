/* Generated By:JJTree: Do not edit this line. ASTReturnStmt.java Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
package analyzer.ast;

public
class ASTReturnStmt extends SimpleNode {
  public ASTReturnStmt(int id) {
    super(id);
  }

  public ASTReturnStmt(Parser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(ParserVisitor visitor, Object data) {

    return
    visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=6e95d8793f33a83ecd553c79c7925816 (do not edit this line) */
