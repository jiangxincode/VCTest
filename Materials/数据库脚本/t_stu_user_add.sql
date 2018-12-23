CREATE TRIGGER t_stu_user_add
ON STUDENT_INFO
FOR INSERT
AS
BEGIN
	DECLARE @userid CHAR(20)
	DECLARE @userpassword CHAR(20)

	SELECT @userid=STU_ID,@userpassword=STU_ID
	FROM INSERTED

	INSERT INTO USERS(USER_ID,USER_PASSWORD,USER_TYPE)
	VALUES(@userid,@userpassword,1)
END