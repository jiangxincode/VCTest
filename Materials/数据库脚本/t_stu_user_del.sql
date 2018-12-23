CREATE TRIGGER t_stu_user_del
ON STUDENT_INFO
FOR DELETE
AS
BEGIN
	DECLARE @userid CHAR(20)
	DECLARE @userpassword CHAR(20)

	SELECT @userid=STU_ID,@userpassword=STU_ID
	FROM DELETED

	DELETE USERS
	WHERE USER_ID=@userid
END