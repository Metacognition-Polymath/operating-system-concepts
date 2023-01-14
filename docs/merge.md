# 공부한 내용을 공용 브랜치에 머지하는 방법

0. 브랜치에서 코드를 다운받습니다

```
git clone https://github.com/Metacognition-Polymath/operating-system-concepts.git
# 해당 폴더를 열어줍니다
cd operating-system-concepts
# Visual studio code 실행
code .
```

1. 본인 닉네임으로 브랜치를 생성합니다

```
git fetch
git checkout -b tony-1 origin/main
```

2. 해당 챕터에 본인 닉네임으로 폴더를 생성 후 공부 내용을 정리합니다

![본인닉네임폴더](../images/%EB%B3%B8%EC%9D%B8%EB%8B%89%EB%84%A4%EC%9E%84%ED%8F%B4%EB%8D%94.png)

- 본인 닉네임으로 폴더를 생성 후 공부 내용을 정리
  - 자유 양식

3. 공부한 내용을 저장 후 github에 push합니다

```
git add .
# 커밋 메세지는 자유롭게 적으셔도 됩니다
git commit -m "tony-1 : 1장 공부 내용 정리"
# git push origin {브랜치명}
git push origin tony-1
```

- `1.`에서 생성한 브랜치명으로 github에 push 합니다

4. 깃허브에서 Pull request를 생성하고 main 브랜치에 머지합니다

![](https://images.velog.io/images/gth1123/post/bca8b32d-0a2d-420c-b624-ee4115cff83e/image.png)

- 위 버튼 클릭

![](https://images.velog.io/images/gth1123/post/50d4ec2c-e2e4-42d3-a449-66674ed25ee3/image.png)

- 간단히 내용을 적고 `Create pull request` 버튼을 누릅니다

![](https://images.velog.io/images/gth1123/post/161dfcbb-ae61-47d6-a287-41f8edffa44a/image.png)

- 머지 후 해당 브랜치는 삭제해줍니다
