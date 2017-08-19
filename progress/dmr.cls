/* class gnai.dmr  */

{gnai/gnvarsx.i}


class gnai.dmr:
  def protected temp-table ttRecords no-undo like gnibcd.
  def public property srcFile as char init "gnibcd.csv" no-undo
    get.
    set.
  def public property outFile as char init "gnibcd.import.log" no-undo
    get.
    set.
  def public property dmrId as char no-undo
    get.
    set.
  def public property mode as char no-undo
    get.
    set.

  constructor public dmr( 
    input p_in_fn as char,
    input p_out_fn as char,
    input p_dmr_id as char,
    input p_mode as char
    ):
    assign
      srcFile = p_in_fn
      outFile = p_out_fn
      dmrId = p_dmr_id
      mode = p_mode
      .
    
  end constructor.

  method public void  loadFile ():
    if search(p_in_fn) = ?
    then do:
      undo, throw new Progress.Lang.AppError("No such file").
    end.

  end method.
  
  method private void logit(
    input p_diff as char,
    input p_cntr as int
  ):
    message"program-name(1) {&line-number} 

  end method.

  method public int loadRecords(
    def input p_mode as char
  ):
    def buffer b_gnibcd for gnibcd.
    def buffer b2_gnibcd for gnibcd.
    def diff as char no-undo.
    deu cntr as int no-undo.

    for each ttRecords :
      find first b_gnibcd no-lock
      where b_gnibcd.ibcode = ttRecords.ibcode
      and b_gnibcd.table_name = ttRecords.table_name
      no-error 
      no-wait.
      if avail b_gnibcd
      then do:
        buffer-compare b_gnibcd 
          except b_gnibcd.last_date b_gnibcd.last_time b_gnibcd.last_usr
          to ttRecords save result in diff.
        if num-items(diff,",") > 0
        then do:
          if p_mode = "update"
          then do:
            find first b2_gnibcd exclusive-lock
            where row-id(b2_gnibcd) = row-id(b_gnibcd).
            buffer-copy ttRecords to b2_gnibcd.
            assign
              b2_gnibcd.last_date = today
              b2_gnibcd.last_time = 
              b2_gnibcd.last_usr  = g_usr
              cntr = cntr + 1.
              .
            logit("change",diff,cntr);
          end.    
          else
            logit("testchange",diff,cntr);
        end.
      end.
      else do:
        if p_mode = "update"
        then do:
          cntr = cntr + 1.
          create b2_gnibcd.
          buffer-copy ttRecords to b2_gnibcd.
          logit("new","",cntr).
        end.
        else
          logit("testnew","",cntr).
      end.
    end.
  end method.





end class.
